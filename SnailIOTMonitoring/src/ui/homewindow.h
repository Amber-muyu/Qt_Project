#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include "../utils/utils.h"
#include "../database/usermanager.h"

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
    void getLoginUserInfo(const QString& msg);
    void userInfoModify();

signals:
    void display(int);
    void changePage(int);

private:
    Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H
