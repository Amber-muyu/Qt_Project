#include "resetpasswdwindow.h"
#include "ui_resetpasswdwindow.h"

ResetPasswdWindow::ResetPasswdWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetPasswdWindow)
{
    ui->setupUi(this);

    ui->lineEditResetPasswd->setPlaceholderText("请输入邮箱或者手机号");
    ui->lineEditResetPasswd->setClearButtonEnabled(true);
    connect(ui->btnResetPasswdOK,&QPushButton::clicked,this,&ResetPasswdWindow::resetReturnLoginPage);
}

void ResetPasswdWindow::resetReturnLoginPage()
{
    UserManager &userManager = UserManager::instance();
    QString msg = ui->lineEditResetPasswd->text();
    if(userManager.resetPassword(msg)){
        ui->lineEditResetPasswd->clear();
        emit sendMessage("重置密码成功");
        emit display(PAGE_LOGIN);
    }else {
        ui->lineEditResetPasswd->clear();
        emit sendMessage("重置密码失败");
    }
}

ResetPasswdWindow::~ResetPasswdWindow()
{
    delete ui;
}
