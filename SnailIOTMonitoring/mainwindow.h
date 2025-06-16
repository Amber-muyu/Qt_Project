#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>
#include "baseframe.h"
#include "titlebar.h"
#include "statusbar.h"
#include "loginwindow.h"
#include "homewindow.h"
#include "registerwindow.h"
#include "resetpasswdwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public BaseFrame
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void showIsMax();

private:
    Ui::MainWindow *ui;
    QStackedLayout* m_stackedLayout;
    TitleBar* m_titleBar;
    StatusBar* m_statusBar;
    LoginWindow* m_loginWindow;
    RegisterWindow* m_registerWindow;
    HomeWindow* m_homeWindow;
    ResetPasswdWindow* m_resetPasswdWindow;
};
#endif // MAINWINDOW_H
