#include "systemlogsmanager.h"

#include <QDebug>
#include <QtConcurrent>
using namespace QXlsx;

SystemLogsManager::SystemLogsManager(QObject *parent)
    : QObject(parent)
{
    m_db = QSqlDatabase::database();          // 默认连接
    if (!m_db.isValid() || (!m_db.isOpen() && !m_db.open())){
        qCritical() << "[SystemLogManager] invalid db connection!";
    }
}

SystemLogsManager &SystemLogsManager::instance()
{
    static SystemLogsManager inst;
    return inst;
}

void SystemLogsManager::log(const QString &type, const QString &level, const QString &content, int userId, int deviceId)
{
    QtConcurrent::run([=]() {
        QVariantMap log;
        log["timestamp"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        log["log_type"] = type;
        log["log_level"] = level;
        log["content"] = content;
        log["user_id"] = userId;
        log["device_id"] = deviceId;

        log["user_id"]   = (userId > 0) ? userId : QVariant(QVariant::Int);
        log["device_id"] = (deviceId > 0) ? deviceId : QVariant(QVariant::Int);

        if (!SystemLogsManager::instance().addLog(log)) {
            qWarning() << "[SystemLogsManager::log] 添加日志失败！";
        }
    });
}

bool SystemLogsManager::addLog(const QVariantMap &logData)
{
    QSqlQuery query(m_db);
    query.prepare(R"(
                  INSERT INTO system_logs (timestamp, log_type, log_level, content, user_id, device_id)
                  VALUES (:timestamp, :log_type, :log_level, :content, :user_id, :device_id)
                  )");

    query.bindValue(":timestamp", logData.value("timestamp", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")));
    query.bindValue(":log_type", logData.value("log_type"));
    query.bindValue(":log_level", logData.value("log_level"));
    query.bindValue(":content", logData.value("content"));
    query.bindValue(":user_id", logData.value("user_id"));
    query.bindValue(":device_id", logData.value("device_id"));

    if (!query.exec()) {
        qWarning() << "Add log failed:" << query.lastError().text();
        return false;
    }

    return true;
}

bool SystemLogsManager::updateLog(int logId, const QVariantMap &updateData)
{
    if (updateData.isEmpty()) return false;

    QStringList setClauses;
    QVariantMap params;
    for (auto it = updateData.begin(); it != updateData.end(); ++it) {
        setClauses << QString("%1 = :%1").arg(it.key());
        params[":" + it.key()] = it.value();
    }

    QString sql = QString("UPDATE system_logs SET %1 WHERE log_id = :log_id")
            .arg(setClauses.join(", "));
    QSqlQuery query(m_db);
    query.prepare(sql);
    for (auto it = params.begin(); it != params.end(); ++it)
        query.bindValue(it.key(), it.value());

    query.bindValue(":log_id", logId);

    if (!query.exec()) {
        qWarning() << "Update log failed:" << query.lastError().text();
        return false;
    }

    return true;
}

bool SystemLogsManager::deleteLog(int logId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM system_logs WHERE log_id = :log_id");
    query.bindValue(":log_id", logId);
    if (!query.exec()) {
        qWarning() << "Delete log failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QVariantMap SystemLogsManager::getLogById(int logId)
{
    QVariantMap result;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM system_logs WHERE log_id = :log_id");
    query.bindValue(":log_id", logId);

    if (query.exec() && query.next()) {
        QSqlRecord rec = query.record();
        for (int i = 0; i < rec.count(); ++i)
            result[rec.fieldName(i)] = query.value(i);
    }

    return result;
}

QList<QVariantMap> SystemLogsManager::getAllLogs()
{
    QList<QVariantMap> list;
    QSqlQuery query("SELECT * FROM system_logs", m_db);

    if(query.exec()){
        while (query.next()) {
            QVariantMap row;
            QSqlRecord rec = query.record();
            for (int i = 0; i < rec.count(); ++i)
                row[rec.fieldName(i)] = query.value(i);
            list << row;
        }
    }

    return list;
}

QList<QVariantMap> SystemLogsManager::getLogsByType(const QString &type)
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM system_logs WHERE log_type = :type");
    query.bindValue(":type", type);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap row;
            QSqlRecord rec = query.record();
            for (int i = 0; i < rec.count(); ++i)
                row[rec.fieldName(i)] = query.value(i);
            list.append(row);
        }
    }

    return list;
}

QList<QVariantMap> SystemLogsManager::getLogsByLevel(const QString &level)
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM system_logs WHERE log_level = :level");
    query.bindValue(":level", level);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap row;
            QSqlRecord rec = query.record();
            for (int i = 0; i < rec.count(); ++i)
                row[rec.fieldName(i)] = query.value(i);
            list.append(row);
        }
    }

    return list;
}

QList<QVariantMap> SystemLogsManager::searchLogs(const QString &keyword)
{
    QList<QVariantMap> result;
    QSqlQuery q(m_db);

    QString pattern = "%" + keyword + "%";
    q.prepare(R"(
              SELECT * FROM system_logs
              WHERE content   LIKE :kw
              OR log_type  LIKE :kw
              OR log_level LIKE :kw
              OR timestamp LIKE :kw
              )");

    q.bindValue(":kw", pattern);

    if (!q.exec()) {
        qWarning() << "Search failed:" << q.lastError();
        return result;
    }

    while (q.next()) {
        QVariantMap row;
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i) {
            row[rec.fieldName(i)] = q.value(i);
        }
        result.append(row);
    }
    return result;
}

QList<QVariantMap> SystemLogsManager::getLogByTimeRange(const QString &start, const QString &end)
{
    QList<QVariantMap> LogList;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM system_logs WHERE timestamp BETWEEN :start AND :end ORDER BY timestamp DESC");
    query.bindValue(":start", start);
    query.bindValue(":end", end);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap log;
            log["log_id"] = query.value("log_id");
            log["timestamp"] = query.value("timestamp");
            log["log_type"] = query.value("log_type");
            log["log_level"] = query.value("log_level");
            log["content"] = query.value("content");
            log["user_id"] = query.value("user_id");
            log["device_id"] = query.value("device_id");
            LogList.append(log);
        }
    } else {
        qWarning() << "Failed to get log by time range:" << query.lastError().text();
    }

    return LogList;
}

bool SystemLogsManager::exportToCsv(const QList<QVariantMap> &data, const QString &filePath)
{
    if (data.isEmpty())
        return false;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning() << "无法打开文件:" << file.errorString();
        return false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");                 // Excel 识别 UTF‑8
    out << QChar(0xFEFF);                  // 写入 BOM，防止中文乱码

    /* 1. 写表头 */
    QStringList headers = {
        "log_id","timestamp","log_type","log_level","content","user_id","device_id"
    };
    out << headers.join(',') << '\n';

    /* 2. 写每行数据：用双引号包裹，并转义内部双引号 */
    for (const QVariantMap &row : data) {
        QStringList line;
        for (const QString &header : headers) {
            QString value = row.value(header).toString();
            // 特殊处理 timestamp 字段（修复时间格式）
            if (header == "timestamp") {
                QDateTime dt = QDateTime::fromString(value, Qt::ISODate);
                if (dt.isValid())
                    value = dt.toString("yyyy-MM-dd HH:mm:ss");
            }
            value.replace('"', "\"\"");          // CSV 规范：双引号转义
            line << '"' + value + '"';
        }
        out << line.join(',') << '\n';
    }
    file.close();
    return true;
}

bool SystemLogsManager::exportToExcel(const QList<QVariantMap> &data, const QString &filePath)
{
    if (data.isEmpty()) return false;

    Document xlsx;
    QStringList headers = {
        "log_id","timestamp","log_type","log_level","content","user_id","device_id"
    };

    // 写入表头
    for (int col = 0; col < headers.size(); ++col) {
        xlsx.write(1, col + 1, headers[col]);
    }

    // 写入数据内容
    for (int row = 0; row < data.size(); ++row) {
        const QVariantMap &rowData = data.at(row);
        for (int col = 0; col < headers.size(); ++col) {
            QVariant value = rowData.value(headers[col]);
            xlsx.write(row + 2, col + 1, value);
        }
    }

    // 保存文件
    return xlsx.saveAs(filePath); // 会自动处理 .xlsx 后缀
}
