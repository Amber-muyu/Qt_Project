#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QList>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include "databasemanager.h"

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    static DataManager& instance();  // 单例模式

    // CRUD 操作
    bool addData(const QVariantMap &data);  // 新增数据
    bool updateData(int dataId, const QVariantMap &updateData);  // 更新数据
    bool deleteData(int dataId);  // 删除单条数据
    bool deleteDataByDeviceId(int deviceId);  // 删除设备关联数据

    // 查询操作
    QVariantMap getDataById(int dataId);  // 根据ID获取单条数据
    QList<QVariantMap> getAllData();  // 获取所有数据
    QList<QVariantMap> getDataByDeviceId(int deviceId);  // 获取设备数据
    QList<QVariantMap> getDataByTimeRange(const QString &start, const QString &end);  // 时间范围查询
    QList<QVariantMap> getDeviceDataByTimeRange(int deviceId, const QDateTime &start, const QDateTime &end);  // 设备+时间范围查询
    QList<QVariantMap> searchData(const QString &keyword);
    // 校验方法
    bool validateData(const QVariantMap &data,bool isInsert);  // 数据校验

    bool exportToCsv (const QList<QVariantMap> &data,const QString &filePath);

private:
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    QSqlDatabase m_db;  // 数据库连接
};

#endif // DATAMANAGER_H
