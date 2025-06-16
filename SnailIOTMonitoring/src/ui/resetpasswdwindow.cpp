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
    emit display(0);
}

ResetPasswdWindow::~ResetPasswdWindow()
{
    delete ui;
}
