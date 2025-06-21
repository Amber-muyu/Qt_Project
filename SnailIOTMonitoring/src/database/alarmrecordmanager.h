#ifndef ALARMRECORDMANAGER_H
#define ALARMRECORDMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QList>

class AlarmRecordManager : public QObject
{
    Q_OBJECT
public:
    explicit AlarmRecordManager(QObject *parent = nullptr);
    static AlarmRecordManager& instance();

    // CRUD
    bool addRecord(const QVariantMap &recordData);
    bool updateRecordById(int alarmId, const QVariantMap &updateData);
    bool deleteRecord(int alarmId);
    // 查询
    QVariantMap getRecordById(int alarmId);
    QList<QVariantMap> getAllRecords();
    QList<QVariantMap> getRecordsByDeviceId(int deviceId);
    QList<QVariantMap> getRecordsByStatus(const QString& status);

    // 校验
    bool validateRecordData(const QVariantMap &recordData, bool isInsert = true);

private:
    AlarmRecordManager(const AlarmRecordManager&) = delete;
    AlarmRecordManager& operator=(const AlarmRecordManager&) = delete;

    QSqlDatabase m_db;
};

#endif // ALARMRECORDMANAGER_H
