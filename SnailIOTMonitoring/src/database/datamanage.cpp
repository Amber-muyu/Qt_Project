#include "datamanage.h"

DataManage::DataManage(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

bool DataManage::openDatabase(const QString &path)
{
    QString dbPath = path.isEmpty() ? getDefaultDatabasePath() : path;

    m_db.setDatabaseName(dbPath);
    if (!m_db.open()) {
        emit databaseError(m_db.lastError().text());
        return false;
    }

    // 检查数据库是否需要初始化
    if (!m_db.tables().contains("users")) {
        if (!initializeDatabase()) {
            emit databaseError("Failed to initialize database");
            return false;
        }
    }

    return true;
}

QString DataManage::getDefaultDatabasePath()
{
    QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appDataPath);
    if (!dir.exists()) dir.mkpath(".");
    return dir.filePath("iot_system.db");
}

void DataManage::closeDatabase()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DataManage::isDatabaseOpen() const
{
    return m_db.isOpen();
}

bool DataManage::initializeDatabase(const QString &schemaPath)
{
    QString scriptPath = schemaPath;
    if (scriptPath.isEmpty()) {
        scriptPath = ":/resources/database_schema.sql"; // 默认资源文件路径
    }

    return executeScriptFromFile(scriptPath);
}

bool DataManage::executeScriptFromFile(const QString &filePath)
{
    QFile scriptFile(filePath);
    if (!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Failed to open SQL script:" << scriptFile.errorString();
        emit databaseError("Failed to open SQL script");
        return false;
    }

    QTextStream stream(&scriptFile);
    QString sqlContent = stream.readAll();
    scriptFile.close();

    // 分割SQL语句
    QStringList sqlStatements = sqlContent.split(';', Qt::SkipEmptyParts);

    QSqlQuery query;
    for (const QString &statement : sqlStatements) {
        QString trimmed = statement.trimmed();
        if (trimmed.isEmpty()) continue;

        if (!query.exec(trimmed)) {
            qCritical() << "Failed to execute SQL:" << trimmed
                        << "\nError:" << query.lastError();
            emit databaseError(query.lastError().text());
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
        emit databaseError(query.lastError().text());
        return false;
    }
    return true;
}

// ========== 用户管理 ==========
bool DataManage::addUser(const QVariantMap &userData)
{
    QString sql = "INSERT INTO users (username, password, email, phone, role) "
                  "VALUES (:username, :password, :email, :phone, :role)";
    return executeQuery(sql, userData);
}

bool DataManage::authenticateUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    if(!query.prepare("SELECT password FROM users WHERE username = :username")){
        return false;
    }
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) {
        return false;
    }

    return (query.value(0).toString() == password);
}


bool DataManage::updateUser(int userId, const QVariantMap &updateData)
{

}

QVariantMap DataManage::getUser(int userId)
{
    QSqlQuery query;
    if(!query.prepare("SELECT * FROM users WHERE user_id = :user_id")){
        return QVariantMap();
    }
    query.bindValue(":user_id", userId);

    if (!query.exec() || !query.next()) {
        return QVariantMap();
    }

    QVariantMap user;
    QSqlRecord record = query.record();
    for (int i = 0; i < record.count(); i++) {
        user[record.fieldName(i)] = query.value(i);
    }
    return user;
}

QList<QVariantMap> DataManage::getAllUsers()
{
    QList<QVariantMap> users;
    QSqlQuery query("SELECT * FROM users");

    while (query.next()) {
        QVariantMap user;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); i++) {
            user[record.fieldName(i)] = query.value(i);
        }
        users.append(user);
    }

    return users;
}

// ========== 设备管理 ==========
int DataManage::addDevice(const QVariantMap &deviceData)
{
    QSqlQuery query;
    if(!query.prepare("INSERT INTO devices (name, type, location, manufacturer, model, status, installation_date)"
                      "VALUES (:name, :type, :location, :manufacturer, :model, :status, :installation_date)")){
        return -1;
    }

    for (auto it = deviceData.begin(); it != deviceData.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) return -1;

    int deviceId = query.lastInsertId().toInt();
    logEvent("操作", "INFO", QString("添加设备: %1").arg(deviceData["name"].toString()));
    return deviceId;
}

bool DataManage::updateDevice(int deviceId, const QVariantMap &updateData)
{
    QString sql = "UPDATE devices SET ";
    QStringList setClauses;
    QVariantMap params = updateData;

    for (auto it = updateData.begin(); it != updateData.end(); ++it) {
        setClauses.append(QString("%1 = :%1").arg(it.key()));
    }

    sql += setClauses.join(", ");
    sql += " WHERE device_id = :device_id";
    params["device_id"] = deviceId;

    return executeQuery(sql, params);
}

bool DataManage::deleteDevice(int deviceId)
{
    QVariantMap params;
    params["device_id"] = deviceId;
    return executeQuery("DELETE FROM devices WHERE device_id = :device_id", params);
}

QVariantMap DataManage::getDevice(int deviceId)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM devices WHERE device_id = :device_id");
    query.bindValue(":device_id", deviceId);

    if (query.exec() && query.next()) {
        QVariantMap device;
        for (int i = 0; i < query.record().count(); i++) {
            device[query.record().fieldName(i)] = query.value(i);
        }
        return device;
    }

    return QVariantMap();
}

QList<QVariantMap> DataManage::getAllDevices()
{

}

// ========== 数据操作 ==========
bool DataManage::insertSensorData(const QVariantMap &sensorData)
{
    QString sql = "INSERT INTO data (device_id, temperature, humidity, light, co2, pressure) "
                  "VALUES (:device_id, :temperature, :humidity, :light, :co2, :pressure)";

    bool success = executeQuery(sql, sensorData);

    if (success) {
        // 这里可以添加告警检查逻辑
        logEvent("数据", "INFO", QString("设备 %1 上传新数据").arg(sensorData["device_id"].toInt()));
    }

    return success;
}

QList<QVariantMap> DataManage::getDeviceData(int deviceId, const QString &timeRange)
{

}

QList<QVariantMap> DataManage::getLatestDeviceData(int deviceId, int limit)
{
    QList<QVariantMap> result;

    QSqlQuery query;
    query.prepare("SELECT * FROM data WHERE device_id = :device_id "
                  "ORDER BY timestamp DESC LIMIT :limit");
    query.bindValue(":device_id", deviceId);
    query.bindValue(":limit", limit);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap data;
            for (int i = 0; i < query.record().count(); i++) {
                data[query.record().fieldName(i)] = query.value(i);
            }
            result.append(data);
        }
    }

    return result;
}

// ========== 告警管理 ==========
bool DataManage::addAlarmRule(const QVariantMap &ruleData)
{

}

bool DataManage::addAlarmRecord(const QVariantMap &alarmData)
{
    QString sql = "INSERT INTO alarm_records (device_id, content) "
                  "VALUES (:device_id, :content)";

    bool success = executeQuery(sql, alarmData);

    if (success) {
        logEvent("告警", "WARNING", alarmData["content"].toString(),
                -1, alarmData["device_id"].toInt());
    }

    return success;
}

bool DataManage::updateAlarmStatus(int alarmId, const QString &status, const QString &note)
{
    QVariantMap params;
    params["alarm_id"] = alarmId;
    params["status"] = status;
    params["note"] = note;

    QString sql = "UPDATE alarm_records SET status = :status, note = :note "
                  "WHERE alarm_id = :alarm_id";

    return executeQuery(sql, params);
}

QList<QVariantMap> DataManage::getUnprocessedAlarms()
{
    QList<QVariantMap> result;

    QSqlQuery query("SELECT * FROM alarm_records WHERE status = '未处理' ORDER BY timestamp DESC");

    while (query.next()) {
        QVariantMap alarm;
        for (int i = 0; i < query.record().count(); i++) {
            alarm[query.record().fieldName(i)] = query.value(i);
        }
        result.append(alarm);
    }

    return result;
}

QList<QVariantMap> DataManage::getAlarmRules(int deviceId)
{
    QList<QVariantMap> result;

    QString sql = "SELECT * FROM alarm_rules";
    if (deviceId != -1) {
        sql += " WHERE device_id = :device_id";
    }

    QSqlQuery query;
    if (!query.prepare(sql)) {
        return result;
    }

    if (deviceId != -1) {
        query.bindValue(":device_id", deviceId);
    }

    if (query.exec()) {
        while (query.next()) {
            QVariantMap rule;
            QSqlRecord record = query.record();
            for (int i = 0; i < record.count(); i++) {
                rule[record.fieldName(i)] = query.value(i);
            }
            result.append(rule);
        }
    }

    return result;
}

// ========== 日志管理 ==========
void DataManage::logEvent(const QString &logType, const QString &logLevel,
                          const QString &content, int userId, int deviceId)
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

QList<QVariantMap> DataManage::getLogs(int limit)
{
    QList<QVariantMap> result;

    QSqlQuery query;
    if(!query.prepare("SELECT * FROM system_logs ORDER BY timestamp DESC LIMIT :limit")){
        return result;
    }
    query.bindValue(":limit", limit);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap log;
            QSqlRecord record = query.record();
            for (int i = 0; i < record.count(); i++) {
                log[record.fieldName(i)] = query.value(i);
            }
            result.append(log);
        }
    }

    return result;
}

DataManage::~DataManage()
{
    closeDatabase();
}
