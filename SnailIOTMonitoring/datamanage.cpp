#include "datamanage.h"

DataManage::DataManage(QObject *parent) : QObject(parent)
{

}

bool DataManage::openDatabase(const QString &path)
{
    m_db.setDatabaseName(path);
    if (!m_db.open()) {
        qCritical() << "Database error:" << m_db.lastError();
        return false;
    }
    return createTables();
}

void DataManage::closeDatabase()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DataManage::createTables()
{
    QStringList tableCreationQueries = {
        // 创建表的SQL语句（与上面提供的SQLite脚本一致）
        // 这里为了节省空间省略，实际使用时需复制上面的SQL脚本
    };

    QSqlQuery query;
    for (const QString &sql : tableCreationQueries) {
        if (!query.exec(sql)) {
            qCritical() << "Table creation failed:" << query.lastError();
            return false;
        }
    }
    return true;
}

bool DataManage::executeQuery(const QString &queryStr, const QVariantMap &params)
{
    QSqlQuery query;
    query.prepare(queryStr);

    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) {
        qCritical() << "Query failed:" << query.lastError()
                    << "\nQuery:" << queryStr;
        return false;
    }
    return true;
}

// 用户管理实现
bool DataManage::addUser(const QVariantMap &userData)
{
    QString sql = "INSERT INTO users (username, password, email, phone, role) "
                  "VALUES (:username, :password, :email, :phone, :role)";
    return executeQuery(sql, userData);
}

bool DataManage::authenticateUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) return false;
    return (query.value(0).toString() == password);
}

// 设备管理实现
int DataManage::addDevice(const QVariantMap &deviceData)
{
    QSqlQuery query;
    query.prepare("INSERT INTO devices (name, type, location, manufacturer, model, status, installation_date) "
                  "VALUES (:name, :type, :location, :manufacturer, :model, :status, :installation_date)");

    for (auto it = deviceData.begin(); it != deviceData.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) return -1;
    return query.lastInsertId().toInt();
}

// 数据操作实现
bool DataManage::insertSensorData(const QVariantMap &sensorData)
{
    QString sql = "INSERT INTO data (device_id, temperature, humidity, light, co2, pressure) "
                  "VALUES (:device_id, :temperature, :humidity, :light, :co2, :pressure)";
    return executeQuery(sql, sensorData);
}

// 告警管理实现
bool DataManage::addAlarmRecord(const QVariantMap &alarmData)
{
    QString sql = "INSERT INTO alarm_records (device_id, content) "
                  "VALUES (:device_id, :content)";
    return executeQuery(sql, alarmData);
}

// 日志记录实现
void DataManage::logEvent(const QString &logType, const QString &logLevel, const QString &content, int userId, int deviceId)
{
    QVariantMap logData;
    logData["log_type"] = logType;
    logData["log_level"] = logLevel;
    logData["content"] = content;
    logData["user_id"] = userId;
    logData["device_id"] = deviceId;

    QString sql = "INSERT INTO system_logs (log_type, log_level, content, user_id, device_id) "
                  "VALUES (:log_type, :log_level, :content, :user_id, :device_id)";
    executeQuery(sql, logData);
}

DataManage::~DataManage()
{
    closeDatabase();
}
