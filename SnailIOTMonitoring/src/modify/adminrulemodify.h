#ifndef ADMINRULEMODIFY_H
#define ADMINRULEMODIFY_H

#include <QWidget>
#include "../database/alarmrulemanager.h"

namespace Ui {
class AdminRuleModify;
}

class AdminRuleModify : public QWidget
{
    Q_OBJECT

public:
    explicit AdminRuleModify(QWidget *parent = nullptr);
    ~AdminRuleModify();

public slots:
    void modifyByRuleId(int);
    void modifyRuleInfo();

signals:
    void modifyFinish(const QString&);

private:
    Ui::AdminRuleModify *ui;
    int m_ruleId = -1;
};

#endif // ADMINRULEMODIFY_H
