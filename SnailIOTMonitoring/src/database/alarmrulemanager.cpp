#include "alarmrulemanager.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AlarmRuleManager::AlarmRuleManager(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::database();
}

AlarmRuleManager& AlarmRuleManager::instance()
{
    static AlarmRuleManager inst;
    return inst;
}

bool AlarmRuleManager::addRule(const QVariantMap &ruleData)
{
    if (!validateRuleData(ruleData, true))
        return false;

    QSqlQuery query(m_db);
    query.prepare(R"(
                  INSERT INTO alarm_rules(device_id, description, condition, action)
                  VALUES(:device_id, :description, :condition, :action)
                  )");
    query.bindValue(":device_id", ruleData.value("device_id"));
    query.bindValue(":description", ruleData.value("description"));
    query.bindValue(":condition", ruleData.value("condition"));
    query.bindValue(":action", ruleData.value("action"));
    return query.exec();
}

bool AlarmRuleManager::updateRuleById(int ruleId, const QVariantMap &updateData)
{
    if (updateData.isEmpty())
        return false;

    if (!validateRuleData(updateData, false))
        return false;

    QStringList setClauses;
    QVariantMap params;
    params[":rule_id"] = ruleId;

    if (updateData.contains("device_id"))
        setClauses.append("device_id = :device_id"), params[":device_id"] = updateData.value("device_id");
    if (updateData.contains("description"))
        setClauses.append("description = :description"), params[":description"] = updateData.value("description");
    if (updateData.contains("condition"))
        setClauses.append("condition = :condition"), params[":condition"] = updateData.value("condition");
    if (updateData.contains("action"))
        setClauses.append("action = :action"), params[":action"] = updateData.value("action");

    if (setClauses.isEmpty())
        return false;

    QString sql = QString("UPDATE alarm_rules SET %1 WHERE rule_id = :rule_id").arg(setClauses.join(", "));
    QSqlQuery query(m_db);
    query.prepare(sql);
    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }
    return query.exec();
}

bool AlarmRuleManager::deleteRule(int ruleId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM alarm_rules WHERE rule_id = :rule_id");
    query.bindValue(":rule_id", ruleId);
    return query.exec();
}

QVariantMap AlarmRuleManager::getRuleById(int ruleId)
{
    QVariantMap result;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM alarm_rules WHERE rule_id = :rule_id");
    query.bindValue(":rule_id", ruleId);
    if (query.exec() && query.next()) {
        result["rule_id"]    = query.value("rule_id");
        result["device_id"]  = query.value("device_id");
        result["description"]= query.value("description");
        result["condition"]  = query.value("condition");
        result["action"]     = query.value("action");
    }
    return result;
}

QList<QVariantMap> AlarmRuleManager::getAllRules()
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    if (query.exec("SELECT * FROM alarm_rules")) {
        while (query.next()) {
            QVariantMap map;
            map["rule_id"]  = query.value("rule_id");
            map["device_id"] = query.value("device_id");
            map["description"] = query.value("description");
            map["condition"]   = query.value("condition");
            map["action"]    = query.value("action");
            list.append(map);
        }
    }
    return list;
}

QList<QVariantMap> AlarmRuleManager::getRulesByDeviceId(int deviceId)
{
    QList<QVariantMap> list;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM alarm_rules WHERE device_id = :device_id");
    query.bindValue(":device_id", deviceId);
    if (query.exec()) {
        while (query.next()) {
            QVariantMap map;
            map["rule_id"]  = query.value("rule_id");
            map["device_id"] = query.value("device_id");
            map["description"] = query.value("description");
            map["condition"]   = query.value("condition");
            map["action"]    = query.value("action");
            list.append(map);
        }
    }
    return list;
}

bool AlarmRuleManager::validateRuleData(const QVariantMap &ruleData, bool isInsert)
{
    // 简单示例
    if (isInsert) {
        if (!ruleData.contains("device_id") || ruleData.value("device_id").toInt() <= 0)
            return false;
        if (!ruleData.contains("description") || ruleData.value("description").toString().isEmpty())
            return false;
        if (!ruleData.contains("condition") || ruleData.value("condition").toString().isEmpty())
            return false;
        if (!ruleData.contains("action") || ruleData.value("action").toString().isEmpty())
            return false;
    }
    // 更新时可选校验

    return true;
}
