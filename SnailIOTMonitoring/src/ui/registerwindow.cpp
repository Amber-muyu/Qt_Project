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
    connect(ui->btnReturn,&QPushButton::clicked,this,[=](){ emit display(PAGE_LOGIN); });
}

void RegisterWindow::registerReturnLoginPage()
{
    UserManager &userManager = UserManager::instance();

    QVariantMap newUser;
    newUser["username"] = ui->lineEditRegisterName->text();
    newUser["password"] = ui->lineEditRegisterPasswd->text();
    newUser["email"] = ui->lineEditRegisterEmail->text();
    newUser["phone"] = ui->lineEditRegisterTelephone->text();
    newUser["role"] = "user";

    if(userManager.addUser(newUser)){
        emit sendMessage("注册成功");
        emit display(PAGE_LOGIN);
        SystemLogsManager::log("操作","INFO",
                               QString("用户：%1 注册成功").arg(newUser["username"].toString()));
        ui->lineEditRegisterName->clear();
        ui->lineEditRegisterPasswd->clear();
        ui->lineEditRegisterEmail->clear();
        ui->lineEditRegisterTelephone->clear();
    }else {
        emit sendMessage("注册失败");
        SystemLogsManager::log("操作","WARNING",
                               QString("用户：%1 注册失败").arg(newUser["username"].toString()));
        ui->lineEditRegisterName->clear();
        ui->lineEditRegisterPasswd->clear();
        ui->lineEditRegisterEmail->clear();
        ui->lineEditRegisterTelephone->clear();
    }
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}
