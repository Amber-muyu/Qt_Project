#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "../database/datamanage.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->lineEditUserName->setPlaceholderText("请输入用户名");
    ui->lineEditUserName->setClearButtonEnabled(true);
    ui->lineEditPassWord->setPlaceholderText("请输入密码");
    ui->lineEditPassWord->setClearButtonEnabled(true);

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

    DataManage db;
    if(!db.openDatabase("")){
        qDebug() << "打开数据库失败";
        return;
    }

    if(db.authenticateUser(username,password)){
        emit display(1);
        emit sendMessage("用户："+username+" 登录成功");
    }
}

void LoginWindow::turnRegisterPage()
{
    emit display(2);
}

void LoginWindow::turnResetPasswdPage()
{
    emit display(3);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
