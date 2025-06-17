#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    //页面切换
    connect(ui->btnUser,&QPushButton::clicked,this,[=]{ emit changePage(0);});
    connect(ui->btnDevice,&QPushButton::clicked,this,[=]{ emit changePage(1);});
    connect(ui->btnData,&QPushButton::clicked,this,[=]{ emit changePage(2);});
    connect(ui->btnAlarm,&QPushButton::clicked,this,[=]{ emit changePage(3);});
    connect(ui->btnDataAnalysis,&QPushButton::clicked,[=]{ emit changePage(4);});
    connect(ui->btnSystem,&QPushButton::clicked,this,[=]{ emit changePage(5);});
    connect(ui->btnLog,&QPushButton::clicked,this,[=]{ emit changePage(6);});

    //用户管理页面
    //connect(ui->btnInfoModify,&QPushButton::clicked,this,&HomeWindow::userInfoModify);

    //登出
    connect(ui->btnLogout,&QPushButton::clicked,this,&HomeWindow::logoutReturnPage);

    connect(this,&HomeWindow::changePage,ui->stackedWidget,&QStackedWidget::setCurrentIndex);
}

void HomeWindow::logoutReturnPage()
{
    emit display(PAGE_LOGIN);
}

void HomeWindow::getLoginUserInfo(const QString &msg)
{
    UserManager usermanager;
    QVariantMap user = usermanager.getUserByUsername(msg);
    ui->labelTextUserName->setText(user.value("username").toString());
    ui->labelTextEmail->setText(user.value("email").toString());
    ui->labelTextPhone->setText(user.value("phone").toString());
    ui->labelTextRole->setText(user.value("role").toString());
}

void HomeWindow::userInfoModify()
{
//    UserManager usermanager;
//    QVariantMap updates;
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
