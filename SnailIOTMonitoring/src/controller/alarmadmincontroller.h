#ifndef ALARMADMINCONTROLLER_H
#define ALARMADMINCONTROLLER_H

#include <QWidget>
#include "../add/adminruleadd.h"
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
    void autoRefresh();

public slots:
    void addRulePage();

private:
    Ui::AlarmAdminController *ui;
    QStandardItemModel* m_modelRule = nullptr;
    AdminRuleAdd* m_adminRuleAdd;
    bool m_isSearching;
};

#endif // ALARMADMINCONTROLLER_H
