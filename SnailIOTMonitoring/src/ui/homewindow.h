#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include "../utils/utils.h"
#include "../controller/usercontroller.h"

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

signals:
    void display(int);
    void changePage(int);
    void loginUserName(const QString&);

private:
    Ui::HomeWindow *ui;
    UserController* m_userController;
};

#endif // HOMEWINDOW_H
