#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    m_userController = new UserController;

    ui->stackedWidget->addWidget(m_userController);

    //页面切换
    connect(ui->btnUser,&QPushButton::clicked,this,[=]{ emit changePage(0);});
    connect(ui->btnDevice,&QPushButton::clicked,this,[=]{ emit changePage(1);});
    connect(ui->btnData,&QPushButton::clicked,this,[=]{ emit changePage(2);});
    connect(ui->btnAlarm,&QPushButton::clicked,this,[=]{ emit changePage(3);});
    connect(ui->btnDataAnalysis,&QPushButton::clicked,[=]{ emit changePage(4);});
    connect(ui->btnSystem,&QPushButton::clicked,this,[=]{ emit changePage(5);});
    connect(ui->btnLog,&QPushButton::clicked,this,[=]{ emit changePage(6);});

    //用户管理页面
    connect(this,&HomeWindow::loginUserName,m_userController,&UserController::getLoginUserInfo);

    //登出
    connect(ui->btnLogout,&QPushButton::clicked,this,&HomeWindow::logoutReturnPage);

    connect(this,&HomeWindow::changePage,ui->stackedWidget,&QStackedWidget::setCurrentIndex);
}

void HomeWindow::logoutReturnPage()
{
    emit display(PAGE_LOGIN);
}

void HomeWindow::getLoginUserName(const QString &msg)
{
    emit loginUserName(msg);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
