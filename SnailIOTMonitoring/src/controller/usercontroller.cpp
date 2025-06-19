#include "usercontroller.h"
#include "ui_usercontroller.h"

#include <QLineEdit>

UserController::UserController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserController)
{
    ui->setupUi(this);

    m_userModify = new UserModify;
    m_passwordModify = new PasswordModify;
    connect(ui->btnInfoModify,&QPushButton::clicked,this,&UserController::userInfoModify);
    connect(m_userModify,&UserModify::modifyFinish,this,&UserController::getLoginUserInfo);

    connect(ui->btnPassWordModify,&QPushButton::clicked,this,&UserController::userPassWordModify);
}

void UserController::getLoginUserInfo(const QString &msg)
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(msg);
    ui->labelTextUserName->setText(user.value("username").toString());
    ui->labelTextEmail->setText(user.value("email").toString());
    ui->labelTextPhone->setText(user.value("phone").toString());
    ui->labelTextRole->setText(user.value("role").toString());
}

void UserController::userInfoModify()
{
    m_userModify->setAttribute(Qt::WA_ShowModal);
    m_userModify->show();
    connect(this,&UserController::sendModifyUserInfo,m_userModify,&UserModify::modifyByUserName);
    emit sendModifyUserInfo(ui->labelTextUserName->text());
}

void UserController::userPassWordModify()
{
    m_passwordModify->setAttribute(Qt::WA_ShowModal);
    m_passwordModify->show();
    connect(this,&UserController::sendModifyUserInfo,m_passwordModify,&PasswordModify::modifyPassWordByUserName);
    emit sendModifyUserInfo(ui->labelTextUserName->text());
}

UserController::~UserController()
{
    delete ui;
}
