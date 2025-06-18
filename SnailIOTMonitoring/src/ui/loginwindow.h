#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "../utils/utils.h"
#include "../database/usermanager.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

public slots:
    void turnMainPage();
    void turnRegisterPage();
    void turnResetPasswdPage();

signals:
    void display(int);
    void sendMessage(const QString&);
    void sendUserNameMessage(const QString&);
private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
