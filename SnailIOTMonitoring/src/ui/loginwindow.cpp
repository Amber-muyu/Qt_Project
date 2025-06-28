#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->lineEditUserName->setPlaceholderText("请输入用户名");
    ui->lineEditUserName->setClearButtonEnabled(true);
    ui->lineEditPassWord->setPlaceholderText("请输入密码");
    ui->lineEditPassWord->setClearButtonEnabled(true);
    ui->lineEditPassWord->setEchoMode(QLineEdit::Password);

    connect(ui->btnLogin,&QPushButton::clicked,this,&LoginWindow::turnMainPage);
    connect(ui->btnRegister,&QPushButton::clicked,this,&LoginWindow::turnRegisterPage);
    connect(ui->btnResetPasswd,&QPushButton::clicked,this,&LoginWindow::turnResetPasswdPage);
};

void LoginWindow::turnMainPage()
{
    QString username = ui->lineEditUserName->text();
    QString password = ui->lineEditPassWord->text();

    if(username.isEmpty()){
        emit sendMessage("请输入用户名");
        ui->lineEditUserName->clear();
        return;
    }
    if(password.isEmpty()){
        emit sendMessage("请输入密码");
        ui->lineEditPassWord->clear();
        return;
    }

    UserManager &userManager = UserManager::instance();

    if(userManager.authenticate(username,password)){
        ui->lineEditUserName->clear();
        ui->lineEditPassWord->clear();
        emit display(PAGE_HOME);
        emit sendMessage("用户："+username+" 登录成功");
        emit sendUserNameMessage(username);
        QVariantMap user = userManager.getUserByUsername(username);
        userManager.setUserId(user.value("user_id").toInt());
    }else {
        ui->lineEditUserName->clear();
        ui->lineEditPassWord->clear();
        emit sendMessage("账号或密码输入错误");
    }
}

void LoginWindow::turnRegisterPage()
{
    emit display(PAGE_REGISERT);
}

void LoginWindow::turnResetPasswdPage()
{
    emit display(PAGE_RESETPASSWD);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
