#include "usermodify.h"
#include "ui_usermodify.h"

#include <QMessageBox>

UserModify::UserModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModify)
{
    ui->setupUi(this);
    connect(ui->btnInfoModifyOK,&QPushButton::clicked,this,&UserModify::modifyUserInfo);
}

void UserModify::modifyByUserName(const QString &msg)
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(msg);
    ui->lineEditModifyUserName->setText(user.value("username").toString());
    ui->lineEditModifyUserName->setEnabled(false);
    ui->lineEditModifyEmail->setText(user.value("email").toString());
    ui->lineEditModifyEmail->setClearButtonEnabled(true);
    ui->lineEditModifyPhone->setText(user.value("phone").toString());
    ui->lineEditModifyPhone->setClearButtonEnabled(true);
    ui->lineEditModifyRole->setText(user.value("role").toString());
    ui->lineEditModifyRole->setEnabled(false);
}

void UserModify::modifyUserInfo()
{
    UserManager &userManager = UserManager::instance();
    int currentUserId = userManager.currentUserId();
    QString username = ui->lineEditModifyUserName->text();

    QVariantMap oldUser = userManager.getUserByUsername(username);

    QString newEmail = ui->lineEditModifyEmail->text();
    QString newPhone = ui->lineEditModifyPhone->text();
    QVariantMap update;
    if(oldUser.value("email").toString() != newEmail){
        update["email"] = newEmail;
    }
    if(oldUser.value("phone").toString() != newPhone){
        update["phone"] = newPhone;
    }

    if(userManager.updateUser(username,update)){
        QMessageBox::information(this,"成功","修改用户信息成功");
        emit modifyFinish(username);
        SystemLogsManager::log("操作","INFO",
                               QString("修改用户：%1 信息成功").arg(oldUser["username"].toString()),currentUserId);
        this->close();
    }else {
        QMessageBox::warning(this,"失败","修改用户信息失败");
        SystemLogsManager::log("操作","WARNING",
                               QString("修改用户：%1 信息失败").arg(oldUser["username"].toString()),currentUserId);
    }
}

UserModify::~UserModify()
{
    delete ui;
}
