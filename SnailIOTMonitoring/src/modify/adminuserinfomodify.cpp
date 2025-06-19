#include "adminuserinfomodify.h"
#include "ui_adminuserinfomodify.h"

#include <QMessageBox>

AdminUserInfoModify::AdminUserInfoModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminUserInfoModify)
{
    ui->setupUi(this);
    connect(ui->btnInfoModifyOK,&QPushButton::clicked,this,&AdminUserInfoModify::modifyUserInfo);
}

void AdminUserInfoModify::modifyByUserId(int msg)
{
    m_userId = msg;
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUser(m_userId);
    ui->lineEditModifyUserName->setText(user.value("username").toString());
    ui->lineEditModifyUserName->setClearButtonEnabled(true);
    ui->lineEditModifyEmail->setText(user.value("email").toString());
    ui->lineEditModifyEmail->setClearButtonEnabled(true);
    ui->lineEditModifyPhone->setText(user.value("phone").toString());
    ui->lineEditModifyPhone->setClearButtonEnabled(true);
    ui->lineEditModifyRole->setText(user.value("role").toString());
    ui->lineEditModifyRole->setClearButtonEnabled(true);
    ui->lineEditModifyPassword->setClearButtonEnabled(true);
}

void AdminUserInfoModify::modifyUserInfo()
{
    UserManager &userManager = UserManager::instance();

    QVariantMap oldUser = userManager.getUser(m_userId);

    QString newUserName = ui->lineEditModifyUserName->text();
    QString newPassword = ui->lineEditModifyPassword->text();
    QString newEmail = ui->lineEditModifyEmail->text();
    QString newPhone = ui->lineEditModifyPhone->text();
    QString newRole = ui->lineEditModifyRole->text();

    QVariantMap update;
    if(oldUser.value("username").toString() != newUserName){
        update["username"] = newUserName;
    }
    if(oldUser.value("email").toString() != newEmail){
        update["email"] = newEmail;
    }
    if(oldUser.value("phone").toString() != newPhone){
        update["phone"] = newPhone;
    }
    if(oldUser.value("role").toString() != newRole){
        update["role"] = newRole;
    }
    if (!newPassword.isEmpty()) {
        update["password"] = newPassword;  // UserManager 会自动 hash
    }
    int userId = oldUser.value("user_id").toInt();
    if(userManager.updateUserById(userId,update)){
        QMessageBox::information(this,"成功","修改用户信息成功");
        emit modifyFinish("修改成功");
        this->close();
    }else {
        QMessageBox::warning(this,"失败","修改用户信息失败");
    }
}

AdminUserInfoModify::~AdminUserInfoModify()
{
    delete ui;
}
