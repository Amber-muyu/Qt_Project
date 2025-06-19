#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include "../utils/utils.h"
#include "../controller/usercontroller.h"
#include "../controller/admincontroller.h"
#include "../controller/deviceusercontroller.h"
#include "../controller/deviceadmincontroller.h"

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

public slots:
    void logoutReturnPage();
    void getLoginUserName(const QString& msg);
    void userPage();
    void devicePage();

signals:
    void display(int);
    void changePage(int);
    void loginUserName(const QString&);

private:
    Ui::HomeWindow *ui;
    QString m_userName;
    UserController* m_userController;
    AdminController* m_adminController;
    DeviceUserController* m_deviceUserController;
    DeviceAdminController* m_deviceAdmincontroller;
};

#endif // HOMEWINDOW_H
