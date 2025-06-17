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
    ui->lineEditRegisterPasswd->setEchoMode(QLineEdit::Password);
    ui->lineEditRegisterEmail->setPlaceholderText("请输入邮箱");
    ui->lineEditRegisterEmail->setClearButtonEnabled(true);
    ui->lineEditRegisterTelephone->setPlaceholderText("请输入电话号码");
    ui->lineEditRegisterTelephone->setClearButtonEnabled(true);

    connect(ui->btnRegisterOK,&QPushButton::clicked,this,&RegisterWindow::registerReturnLoginPage);
}

void RegisterWindow::registerReturnLoginPage()
{
    UserManager userManager;

    QVariantMap newUser;
    newUser["username"] = ui->lineEditRegisterName->text();
    newUser["password"] = ui->lineEditRegisterPasswd->text();
    newUser["email"] = ui->lineEditRegisterEmail->text();
    newUser["phone"] = ui->lineEditRegisterTelephone->text();
    newUser["role"] = "user";

    if(userManager.addUser(newUser)){
        ui->lineEditRegisterName->clear();
        ui->lineEditRegisterPasswd->clear();
        ui->lineEditRegisterEmail->clear();
        ui->lineEditRegisterTelephone->clear();
        emit sendMessage("注册成功");
        emit display(PAGE_LOGIN);
    }else {
        ui->lineEditRegisterName->clear();
        ui->lineEditRegisterPasswd->clear();
        ui->lineEditRegisterEmail->clear();
        ui->lineEditRegisterTelephone->clear();
        emit sendMessage("注册失败");
    }
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
