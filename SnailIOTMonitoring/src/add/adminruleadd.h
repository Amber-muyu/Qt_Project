#ifndef ADMINRULEADD_H
#define ADMINRULEADD_H

#include <QWidget>
#include "../database/alarmrulemanager.h"

namespace Ui {
class AdminRuleAdd;
}

class AdminRuleAdd : public QWidget
{
    Q_OBJECT

public:
    explicit AdminRuleAdd(QWidget *parent = nullptr);
    ~AdminRuleAdd();

public slots:
    void addRuleInfo();

signals:
    void addFinish(const QString&);

private:
    Ui::AdminRuleAdd *ui;
};

#endif // ADMINRULEADD_H
