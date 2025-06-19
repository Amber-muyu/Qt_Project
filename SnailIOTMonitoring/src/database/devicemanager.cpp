#include "devicemanager.h"
#include <QDebug>

static const QString kStatusOnline  = "ONLINE";
static const QString kStatusOffline = "OFFLINE";
static const QString kStatusFault   = "FAULT";

DeviceManager::DeviceManager(QObject *parent)
    : QObject(parent)
{
    m_db = QSqlDatabase::database();          // 默认连接
    if (!m_db.isValid() || !m_db.isOpen())
        qCritical() << "[DeviceManager] invalid db connection!";
}

// 单例
DeviceManager& DeviceManager::instance()
{
    static DeviceManager dm;
    return dm;
}

// 工具：校验输入
bool DeviceManager::validateDeviceData(const QVariantMap &d, bool isInsert)
{
    // name 必填
    if ((!d.contains("name") || d["name"].toString().trimmed().isEmpty()) && isInsert) {
        qWarning() << "Device name required";
        return false;
    }
    // status 校验
    if (d.contains("status")) {
        const QString s = d["status"].toString();
        if (s != kStatusOnline && s != kStatusOffline && s != kStatusFault) {
            qWarning() << "Invalid status:" << s;
            return false;
        }
    }
    return true;
}

// 工具：唯一性校验
bool DeviceManager::isNameExist(const QString &name, int excludeId)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT 1 FROM devices WHERE name = :n AND device_id <> :id LIMIT 1");
    q.bindValue(":n", name);
    q.bindValue(":id", excludeId);
    return q.exec() && q.next();
}

bool DeviceManager::isModelExist(const QString &model, int excludeId)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT 1 FROM devices WHERE model = :m AND device_id <> :id LIMIT 1");
    q.bindValue(":m", model);
    q.bindValue(":id", excludeId);
    return q.exec() && q.next();
}

// 新增
bool DeviceManager::addDevice(const QVariantMap &d)
{
    if (!validateDeviceData(d, /*insert=*/true))
        return false;

    if (isNameExist(d["name"].toString())) {
        qWarning() << "Device name exists:" << d["name"].toString();
        return false;
    }

    QDateTime installTime = d.value("installation_date").toDateTime();
    if (!installTime.isValid()) {
        installTime = QDateTime::currentDateTime(); //默认当前时间
    }

    QSqlQuery q(m_db);
    q.prepare(R"(
              INSERT INTO devices
              (name, type, location, manufacturer, model, status, installation_date)
              VALUES (:name, :type, :location, :manu, :model, :status, :install)
              )");
    q.bindValue(":name",   d.value("name"));
    q.bindValue(":type",   d.value("type"));
    q.bindValue(":location", d.value("location"));
    q.bindValue(":manu",   d.value("manufacturer"));
    q.bindValue(":model",  d.value("model"));
    q.bindValue(":status", d.value("status", kStatusOnline));
    q.bindValue(":install", installTime);

    if (!q.exec()) {
        qCritical() << "Add device failed:" << q.lastError().text();
        return false;
    }
    return true;
}

// 更新
bool DeviceManager::updateDeviceById(int id,
                                     const QVariantMap &upd)
{
    if (upd.isEmpty())
        return false;
    if (!validateDeviceData(upd, /*insert=*/false))
        return false;

    // 唯一性
    if (upd.contains("name") &&
            isNameExist(upd["name"].toString(), id)) {
        qWarning() << "Device name exists:" << upd["name"].toString();
        return false;
    }
    if (upd.contains("model") &&
            isModelExist(upd["model"].toString(), id)) {
        qWarning() << "Device model exists:" << upd["model"].toString();
        return false;
    }

    QStringList setClauses;
    QVariantMap params;
    params["id"] = id;

    for (auto it = upd.begin(); it != upd.end(); ++it) {
        setClauses << QString("%1 = :%1").arg(it.key());
        params[it.key()] = it.value();
    }
    setClauses << "installation_date = IFNULL(:installation_date, installation_date)";

    QString sql = QString("UPDATE devices SET %1 WHERE device_id = :id")
            .arg(setClauses.join(", "));

    QSqlQuery q(m_db);
    q.prepare(sql);
    for (auto it = params.begin(); it != params.end(); ++it)
        q.bindValue(":" + it.key(), it.value());

    if (!q.exec()) {
        qCritical() << "Update device failed:" << q.lastError().text();
        return false;
    }
    return q.numRowsAffected() > 0;
}

// 删除
bool DeviceManager::deleteDevice(int id)
{
    QSqlQuery q(m_db);
    q.prepare("DELETE FROM devices WHERE device_id = :id");
    q.bindValue(":id", id);
    if (!q.exec()) {
        qCritical() << "Delete device failed:" << q.lastError().text();
        return false;
    }
    return q.numRowsAffected() > 0;
}

// 查询
QVariantMap DeviceManager::getDeviceById(int id)
{
    QSqlQuery q(m_db);
    q.prepare("SELECT * FROM devices WHERE device_id = :id");
    q.bindValue(":id", id);
    QVariantMap dev;
    if (q.exec() && q.next()) {
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i)
            dev[rec.fieldName(i)] = q.value(i);
    }
    return dev;
}

QList<QVariantMap> DeviceManager::getAllDevices()
{
    QList<QVariantMap> list;
    QSqlQuery q("SELECT * FROM devices ORDER BY name", m_db);
    while (q.next()) {
        QVariantMap dev;
        QSqlRecord rec = q.record();
        for (int i = 0; i < rec.count(); ++i)
            dev[rec.fieldName(i)] = q.value(i);
        list << dev;
    }
    return list;
}

QList<QVariantMap> DeviceManager::searchDevices(const QString &keyword)
{
    QList<QVariantMap> devices;

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT * FROM devices
        WHERE name LIKE :kw OR
              type LIKE :kw OR
              location LIKE :kw OR
              manufacturer LIKE :kw OR
              model LIKE :kw
        ORDER BY installation_date DESC
    )");

    query.bindValue(":kw", "%" + keyword + "%");

    if (!query.exec()) {
        qWarning() << "Search failed:" << query.lastError().text();
        return devices;
    }

    while (query.next()) {
        QVariantMap device;
        for (int i = 0; i < query.record().count(); ++i) {
            device[query.record().fieldName(i)] = query.value(i);
        }
        devices.append(device);
    }

    return devices;
}
