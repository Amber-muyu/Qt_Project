#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <QObject>
#include <QVariantMap>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include "databasemanager.h"

class DeviceManager : public QObject
{
    Q_OBJECT
public:
    explicit DeviceManager(QObject *parent = nullptr);
    static DeviceManager& instance();                 // 单例
    // CRUD
    bool addDevice(const QVariantMap &deviceData);    // 新增
    bool updateDeviceById(int deviceId,const QVariantMap &updateData);
    bool deleteDevice(int deviceId);
    // 查询
    QVariantMap getDeviceById(int deviceId);
    QList<QVariantMap> getAllDevices();
    QList<QVariantMap> searchDevices(const QString &keyword);
    // 校验
    bool isNameExist(const QString &name,int excludeId = -1);
    bool isModelExist(const QString &model,int excludeId = -1);
    // 校验输入数据合法性（必填、枚举等）
    bool validateDeviceData(const QVariantMap &deviceData,bool isInsert = true);

private:
    DeviceManager(const DeviceManager&) = delete;
    DeviceManager& operator=(const DeviceManager&) = delete;

    QSqlDatabase m_db;

};

#endif // DEVICEMANAGER_H
