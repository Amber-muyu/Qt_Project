#ifndef DATAMANAGE_H
#define DATAMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariantMap>
#include <QList>

class DataManage : public QObject
{
    Q_OBJECT
public:
    explicit DataManage(QObject *parent = nullptr);
    ~DataManage();

    // 数据库连接管理
    bool openDatabase(const QString &path);
    void closeDatabase();

    // 用户管理
    bool addUser(const QVariantMap &userData);
    bool authenticateUser(const QString &username, const QString &password);
    bool updateUser(int userId, const QVariantMap &updateData);
    QVariantMap getUser(int userId);

    // 设备管理
    int addDevice(const QVariantMap &deviceData);
    bool updateDevice(int deviceId, const QVariantMap &updateData);
    QVariantMap getDevice(int deviceId);
    QList<QVariantMap> getAllDevices();

    // 数据操作
    bool insertSensorData(const QVariantMap &sensorData);
    QList<QVariantMap> getDeviceData(int deviceId, const QString &timeRange = "24 HOURS");

    // 告警管理
    bool addAlarmRecord(const QVariantMap &alarmData);
    bool updateAlarmStatus(int alarmId, const QString &status, const QString &note = "");
    QList<QVariantMap> getUnprocessedAlarms();

    // 日志记录
    void logEvent(const QString &logType, const QString &logLevel, const QString &content, int userId = -1, int deviceId = -1);

private:
    QSqlDatabase m_db;
    bool createTables();
    bool executeQuery(const QString &query, const QVariantMap &params = QVariantMap());
};

#endif // DATAMANAGE_H
