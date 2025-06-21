#include "alarmrecordmanager.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

AlarmRecordManager::AlarmRecordManager(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::database();
}

AlarmRecordManager& AlarmRecordManager::instance()
{
    static AlarmRecordManager inst;
    return inst;
}

bool AlarmRecordManager::addRecord(const QVariantMap &recordData)
{
    if (!validateRecordData(recordData, true))
        return false;

    QSqlQuery query(m_db);
    query.prepare(R"(
                  INSERT INTO alarm_records(device_id, timestamp, content, status, note)
                  VALUES(:device_id, :timestamp, :content, :status, :note)
                  )");
    query.bindValue(":device_id", recordData.value("device_id"));
    query.bindValue(":timestamp", recordData.value("timestamp"));
    query.bindValue(":content", recordData.value("content"));
    query.bindValue(":status", recordData.value("status", "UNHANDLED"));
    query.bindValue(":note", recordData.value("note"));
    return query.exec();
}

bool AlarmRecordManager::updateRecordById(int alarmId, const QVariantMap &updateData)
{
    if (updateData.isEmpty())
        return false;

    if (!validateRecordData(updateData, false))
        return false;

    QStringList setClauses;
    QVariantMap params;
    params[":alarm_id"] = alarmId;

    if (updateData.contains("device_id"))
        setClauses.append("device_id = :device_id"), params[":device_id"] = updateData.value("device_id");
    if (updateData.contains("timestamp"))
        setClauses.append("timestamp = :timestamp"), params[":timestamp"] = updateData.value("timestamp");
    if (updateData.contains("content"))
        setClauses.append("content = :content"), params[":content"] = updateData.value("content");
    if (updateData.contains("status"))
        setClauses.append("status = :status"), params[":status"] = updateData.value("status");
    if (updateData.contains("note"))
        setClauses.append("note = :note"), params[":note"] = updateData.value("note");

    if (setClauses.isEmpty())
        return false;

    QString sql = QString("UPDATE alarm_records SET %1 WHERE alarm_id = :alarm_id").arg(setClauses.join(", "));
    QSqlQuery query(m_db);
    query.prepare(sql);
    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }
    return query.exec();
}

bool AlarmRecordManager::deleteRecord(int alarmId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM alarm_records WHERE alarm_id = :alarm_id");
    query.bindValue(":alarm_id", alarmId);
    return query.exec();
}

QVariantMap AlarmRecordManager::getRecordById(int alarmId)
{
    QVariantMap result;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM alarm_records WHERE alarm_id = :alarm_id");
    query.bindValue(":alarm_id", alarmId);
    if (query.exec() && query.next()) {
        QSqlRecord rec = query.record();
        for(int i=0;i<rec.count();++i)
            result[rec.fieldName(i)] = query.value(i);
    }
    return result;
}

QList<QVariantMap> AlarmRecordManager::getAllRecords()
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    if (query.exec("SELECT * FROM alarm_records ORDER BY timestamp DESC")) {
        while (query.next()) {
            QVariantMap map;
            map["alarm_id"]  = query.value("alarm_id");
            map["device_id"] = query.value("device_id");
            map["timestamp"] = query.value("timestamp");
            map["content"]   = query.value("content");
            map["status"]    = query.value("status");
            map["note"]      = query.value("note");
            list.append(map);
        }
    }
    return list;
}

QList<QVariantMap> AlarmRecordManager::getRecordsByDeviceId(int deviceId)
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM alarm_records WHERE device_id = :device_id ORDER BY timestamp DESC");
    query.bindValue(":device_id", deviceId);
    if (query.exec()) {
        while (query.next()) {
            QVariantMap map;
            map["alarm_id"]  = query.value("alarm_id");
            map["device_id"] = query.value("device_id");
            map["timestamp"] = query.value("timestamp");
            map["content"]   = query.value("content");
            map["status"]    = query.value("status");
            map["note"]      = query.value("note");
            list.append(map);
        }
    }
    return list;
}

QList<QVariantMap> AlarmRecordManager::getRecordsByStatus(const QString& status)
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM alarm_records WHERE status = :status ORDER BY timestamp DESC");
    query.bindValue(":status", status);
    if (query.exec()) {
        while (query.next()) {
            QVariantMap map;
            map["alarm_id"]  = query.value("alarm_id");
            map["device_id"] = query.value("device_id");
            map["timestamp"] = query.value("timestamp");
            map["content"]   = query.value("content");
            map["status"]    = query.value("status");
            map["note"]      = query.value("note");
            list.append(map);
        }
    }
    return list;
}

bool AlarmRecordManager::validateRecordData(const QVariantMap &recordData, bool isInsert)
{
    if (isInsert) {
        if (!recordData.contains("device_id") || recordData.value("device_id").toInt() <= 0)
            return false;
        if (!recordData.contains("timestamp") || !recordData.value("timestamp").canConvert<QDateTime>())
            return false;
        if (!recordData.contains("content") || recordData.value("content").toString().isEmpty())
            return false;
        if (recordData.contains("status")) {
            QString status = recordData.value("status").toString();
            if (status != "UNHANDLED" && status != "HANDLED")
                return false;
        }
    }
    return true;
}
