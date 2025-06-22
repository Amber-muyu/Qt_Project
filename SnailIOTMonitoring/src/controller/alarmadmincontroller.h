#ifndef ALARMADMINCONTROLLER_H
#define ALARMADMINCONTROLLER_H

#include <QWidget>
#include "../add/adminruleadd.h"
#include "../modify/adminrulemodify.h"
#include <QStandardItemModel>
#include <QTimer>
#include "../database/alarmrecordmanager.h"
#include "../database/alarmrulemanager.h"

namespace Ui {
class AlarmAdminController;
}

class AlarmAdminController : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmAdminController(QWidget *parent = nullptr);
    ~AlarmAdminController();
    void initRuleInfoPage(const QList<QVariantMap>& rules);
    void initRecordInfoPage(const QList<QVariantMap>& records);
    void autoRefresh();

public slots:
    void addRulePage();
    void deleteRule();
    void modifyRulePage();
    void deleteRecord();
    void modifyRecordPage();

signals:
    void sendModifyRuleInfo(int);

private:
    Ui::AlarmAdminController *ui;
    QStandardItemModel* m_modelRule = nullptr;
    QStandardItemModel* m_modelRecord = nullptr;
    AdminRuleAdd* m_adminRuleAdd;
    AdminRuleModify* m_adminRuleModify;
    bool m_isSearching;
};

#endif // ALARMADMINCONTROLLER_H
