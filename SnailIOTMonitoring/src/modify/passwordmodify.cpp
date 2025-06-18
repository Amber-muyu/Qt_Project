#include "passwordmodify.h"
#include "ui_passwordmodify.h"

#include <QMessageBox>

PasswordModify::PasswordModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordModify)
{
    ui->setupUi(this);
    connect(ui->btnPassWordModifyOK,&QPushButton::clicked,this,&PasswordModify::modifyUserPassword);
}

void PasswordModify::modifyPassWordByUserName(const QString &msg)
{
    ui->lineEditModifyUserName->setText(msg);
    ui->lineEditModifyUserName->setEnabled(false);
    ui->lineEditModifyOldPassword->setClearButtonEnabled(true);
    ui->lineEditModifyOldPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditModifyNewPassword->setClearButtonEnabled(true);
    ui->lineEditModifyNewPassword->setEchoMode(QLineEdit::Password);
}

void PasswordModify::modifyUserPassword()
{
    UserManager &userManager = UserManager::instance();
    QString username = ui->lineEditModifyUserName->text();

    QVariantMap oldUser = userManager.getUserByUsername(username);

    QString oldPassword = ui->lineEditModifyOldPassword->text();
    QString newPassword = ui->lineEditModifyNewPassword->text();
    QVariantMap update;

    if(oldUser.value("password").toString() == userManager.hashPassword(oldPassword)){
        if(userManager.changePassword(username,newPassword)){
            QMessageBox::information(this,"成功","修改密码成功!");
            this->close();
        }else {
            QMessageBox::warning(this,"失败","修改密码失败!");
        }
    }else {
        QMessageBox::warning(this,"失败","旧密码输入错误!");
        return;
    }
}

PasswordModify::~PasswordModify()
{
    delete ui;
}
