#ifndef ADMINUSERINFOADD_H
#define ADMINUSERINFOADD_H

#include <QWidget>
#include "../database/usermanager.h"
#include "../database/systemlogsmanager.h"

namespace Ui {
class AdminUserInfoAdd;
}

class AdminUserInfoAdd : public QWidget
{
    Q_OBJECT

public:
    explicit AdminUserInfoAdd(QWidget *parent = nullptr);
    ~AdminUserInfoAdd();

public slots:
    void addUserInfo();

signals:
    void addFinish(const QString&);

private:
    Ui::AdminUserInfoAdd *ui;
};

#endif // ADMINUSERINFOADD_H
