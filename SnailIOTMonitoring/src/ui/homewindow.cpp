#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    m_userController = new UserController;
    m_adminController = new AdminController;

    ui->stackedWidget->addWidget(m_userController);
    ui->stackedWidget->addWidget(m_adminController);

    //页面切换
    connect(ui->btnUser,&QPushButton::clicked,this,&HomeWindow::userPage);
    connect(ui->btnDevice,&QPushButton::clicked,this,[=](){ emit changePage(3);});
    connect(ui->btnData,&QPushButton::clicked,this,[=](){ emit changePage(3);});
    connect(ui->btnAlarm,&QPushButton::clicked,this,[=](){ emit changePage(4);});
    connect(ui->btnDataAnalysis,&QPushButton::clicked,[=](){ emit changePage(5);});
    connect(ui->btnSystem,&QPushButton::clicked,this,[=](){ emit changePage(6);});
    connect(ui->btnLog,&QPushButton::clicked,this,[=](){ emit changePage(7);});

    //用户管理页面
    connect(this,&HomeWindow::loginUserName,m_userController,&UserController::getLoginUserInfo);

    //登出
    connect(ui->btnLogout,&QPushButton::clicked,this,&HomeWindow::logoutReturnPage);

    connect(this,&HomeWindow::changePage,ui->stackedWidget,&QStackedWidget::setCurrentIndex);
}

void HomeWindow::userPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(1);
    }else {
        emit changePage(2);
    }
}


void HomeWindow::logoutReturnPage()
{
    emit changePage(0);
    emit display(PAGE_LOGIN);
}

void HomeWindow::getLoginUserName(const QString &msg)
{
    m_userName = msg;
    emit loginUserName(msg);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
