#ifndef DATAMANAGE_H
#define DATAMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QVariantMap>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>

class DataManage : public QObject
{
    Q_OBJECT
public:
    explicit DataManage(QObject *parent = nullptr);
    ~DataManage();

    // 数据库连接管理
    bool openDatabase(const QString &path);
    void closeDatabase();
    bool isDatabaseOpen() const;

    // 数据库初始化
    bool initializeDatabase(const QString &schemaPath = "");

    // 用户管理
    bool addUser(const QVariantMap &userData);
    bool authenticateUser(const QString &username, const QString &password);
    bool updateUser(int userId, const QVariantMap &updateData);
    QVariantMap getUser(int userId);
    QList<QVariantMap> getAllUsers();

    // 设备管理
    int addDevice(const QVariantMap &deviceData);
    bool updateDevice(int deviceId, const QVariantMap &updateData);
    bool deleteDevice(int deviceId);
    QVariantMap getDevice(int deviceId);
    QList<QVariantMap> getAllDevices();

    // 数据操作
    bool insertSensorData(const QVariantMap &sensorData);
    QList<QVariantMap> getDeviceData(int deviceId, const QString &timeRange = "24 HOURS");
    QList<QVariantMap> getLatestDeviceData(int deviceId, int limit = 10);

    // 警告管理
    bool addAlarmRule(const QVariantMap &ruleData);
    bool addAlarmRecord(const QVariantMap &alarmData);
    bool updateAlarmStatus(int alarmId, const QString &status, const QString &note = "");
    QList<QVariantMap> getUnprocessedAlarms();
    QList<QVariantMap> getAlarmRules(int deviceId = -1);

    // 日志记录
    void logEvent(const QString &logType, const QString &logLevel, const QString &content, int userId = -1, int deviceId = -1);
    QList<QVariantMap> getLogs(int limit = 100);

signals:
    void databaseError(const QString &error);

private:
    QSqlDatabase m_db;
    bool executeQuery(const QString &query, const QVariantMap &params = QVariantMap());
    bool executeScriptFromFile(const QString &filePath);
    QString getDefaultDatabasePath();
};

#endif // DATAMANAGE_H
