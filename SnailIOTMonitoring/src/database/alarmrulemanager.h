#ifndef ALARMRULEMANAGER_H
#define ALARMRULEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QList>

class AlarmRuleManager : public QObject
{
    Q_OBJECT
public:
    explicit AlarmRuleManager(QObject *parent = nullptr);
    static AlarmRuleManager& instance();

    bool addRule(const QVariantMap &ruleData);
    bool updateRuleById(int ruleId, const QVariantMap &updateData);
    bool deleteRule(int ruleId);

    // 查询
    QVariantMap getRuleById(int ruleId);
    QList<QVariantMap> getAllRules();
    QList<QVariantMap> getRulesByDeviceId(int deviceId);

    // 校验
    bool validateRuleData(const QVariantMap &ruleData, bool isInsert = true);

private:
    AlarmRuleManager(const AlarmRuleManager&) = delete;
    AlarmRuleManager& operator=(const AlarmRuleManager&) = delete;

    QSqlDatabase m_db;
};

#endif // ALARMRULEMANAGER_H
