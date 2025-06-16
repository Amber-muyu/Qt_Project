#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->lineEditRegisterName->setPlaceholderText("请输入用户名");
    ui->lineEditRegisterName->setClearButtonEnabled(true);
    ui->lineEditRegisterPasswd->setPlaceholderText("请输入密码");
    ui->lineEditRegisterPasswd->setClearButtonEnabled(true);
    ui->lineEditRegisterEmail->setPlaceholderText("请输入邮箱");
    ui->lineEditRegisterEmail->setClearButtonEnabled(true);
    ui->lineEditRegisterTelephone->setPlaceholderText("请输入电话号码");
    ui->lineEditRegisterTelephone->setClearButtonEnabled(true);

    connect(ui->btnRegisterOK,&QPushButton::clicked,this,&RegisterWindow::registerReturnLoginPage);
}

void RegisterWindow::registerReturnLoginPage()
{
    emit display(0);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
