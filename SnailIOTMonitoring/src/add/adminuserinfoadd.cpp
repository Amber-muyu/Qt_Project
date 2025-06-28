#include "adminuserinfoadd.h"
#include "ui_adminuserinfoadd.h"

#include <QMessageBox>

AdminUserInfoAdd::AdminUserInfoAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminUserInfoAdd)
{
    ui->setupUi(this);
    ui->lineEditAddName->setPlaceholderText("请输入用户名");
    ui->lineEditAddName->setClearButtonEnabled(true);
    ui->lineEditAddPasswd->setPlaceholderText("请输入密码");
    ui->lineEditAddPasswd->setClearButtonEnabled(true);
    ui->lineEditAddPasswd->setEchoMode(QLineEdit::Password);
    ui->lineEditAddEmail->setPlaceholderText("请输入邮箱");
    ui->lineEditAddEmail->setClearButtonEnabled(true);
    ui->lineEditAddTelephone->setPlaceholderText("请输入电话号码");
    ui->lineEditAddTelephone->setClearButtonEnabled(true);
    connect(ui->btnAddOK,&QPushButton::clicked,this,&AdminUserInfoAdd::addUserInfo);
}

void AdminUserInfoAdd::addUserInfo()
{
    UserManager &userManager = UserManager::instance();
    int currentUserId = userManager.currentUserId();
    QVariantMap newUser;
    newUser["username"] = ui->lineEditAddName->text();
    newUser["password"] = ui->lineEditAddPasswd->text();
    newUser["email"] = ui->lineEditAddEmail->text();
    newUser["phone"] = ui->lineEditAddTelephone->text();
    newUser["role"] = "user";

    if(userManager.addUser(newUser)){
        QMessageBox::information(this,"成功","新增用户成功!");
        ui->lineEditAddName->clear();
        ui->lineEditAddPasswd->clear();
        ui->lineEditAddEmail->clear();
        ui->lineEditAddTelephone->clear();
        emit addFinish("注册成功");
        SystemLogsManager::log("操作","INFO",
                               QString("新增用户：%1 成功").arg(newUser["username"].toString()),currentUserId);
        this->close();
    }else {
        ui->lineEditAddName->clear();
        ui->lineEditAddPasswd->clear();
        ui->lineEditAddEmail->clear();
        ui->lineEditAddTelephone->clear();
        QMessageBox::warning(this,"失败","新增用户失败!");
        SystemLogsManager::log("操作","WARNING",
                               QString("新增用户：%1 失败").arg(newUser["username"].toString()),currentUserId);
    }
}

AdminUserInfoAdd::~AdminUserInfoAdd()
{
    delete ui;
}
