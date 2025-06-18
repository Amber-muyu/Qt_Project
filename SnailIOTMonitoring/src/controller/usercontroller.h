#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QWidget>
#include "../modify/usermodify.h"
#include "../modify/passwordmodify.h"
#include "../database/usermanager.h"

namespace Ui {
class UserController;
}

class UserController : public QWidget
{
    Q_OBJECT

public:
    explicit UserController(QWidget *parent = nullptr);
    ~UserController();

public slots:
    void getLoginUserInfo(const QString&);
    void userInfoModify();
    void userPassWordModify();

signals:
    void sendModifyUserInfo(const QString&);

private:
    Ui::UserController *ui;
    UserModify* m_userModify;
    PasswordModify* m_passwordModify;
};

#endif // USERCONTROLLER_H
