#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);

    m_userController = new UserController;
    m_adminController = new AdminController;
    m_deviceUserController = new DeviceUserController;
    m_deviceAdmincontroller = new DeviceAdminController;
    m_dataUserController = new DataUserController;
    m_dataAdminController = new DataAdminController;
    m_alarmUserController = new AlarmUserController;
    m_alarmAdminController = new AlarmAdminController;
    m_userDataAnalysisController = new UserDataAnalysisController;
    m_adminDataAnalysisController = new AdminDataAnalysisController;
    m_systemLogUserController = new SystemLogUserController;
    m_systemLogAdminController = new SystemLogAdminController;

    ui->stackedWidget->addWidget(m_userController);
    ui->stackedWidget->addWidget(m_adminController);
    ui->stackedWidget->addWidget(m_deviceUserController);
    ui->stackedWidget->addWidget(m_deviceAdmincontroller);
    ui->stackedWidget->addWidget(m_dataUserController);
    ui->stackedWidget->addWidget(m_dataAdminController);
    ui->stackedWidget->addWidget(m_alarmUserController);
    ui->stackedWidget->addWidget(m_alarmAdminController);
    ui->stackedWidget->addWidget(m_userDataAnalysisController);
    ui->stackedWidget->addWidget(m_adminDataAnalysisController);
    ui->stackedWidget->addWidget(m_systemLogUserController);
    ui->stackedWidget->addWidget(m_systemLogAdminController);

    //页面切换
    connect(ui->btnUser,&QPushButton::clicked,this,&HomeWindow::userPage);
    connect(ui->btnDevice,&QPushButton::clicked,this,&HomeWindow::devicePage);
    connect(ui->btnData,&QPushButton::clicked,this,&HomeWindow::dataPage);
    connect(ui->btnAlarm,&QPushButton::clicked,this,&HomeWindow::alarmPage);
    connect(ui->btnDataAnalysis,&QPushButton::clicked,this,&HomeWindow::dataAnalysisPage);
    connect(ui->btnSystem,&QPushButton::clicked,this,&HomeWindow::systemLogPage);
    connect(ui->btnLog,&QPushButton::clicked,this,[=](){ emit changePage(50);});

    //用户管理页面
    connect(this,&HomeWindow::loginUserName,m_userController,&UserController::getLoginUserInfo);

    //登出
    connect(ui->btnLogout,&QPushButton::clicked,this,&HomeWindow::logoutReturnPage);

    //界面切换
    connect(this,&HomeWindow::changePage,ui->stackedWidget,&QStackedWidget::setCurrentIndex);
}

void HomeWindow::userPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_USERINFO_USER);
    }else {
        emit changePage(PAGE_USERINFO_ADMIN);
    }
}

void HomeWindow::devicePage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_DEVICE_USER);
    }else {
        emit changePage(PAGE_DEVICE_ADMIN);
    }
}

void HomeWindow::dataPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_DATA_USER);
    }else {
        emit changePage(PAGE_DATA_ADMIN);
    }
}

void HomeWindow::alarmPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_ALARM_USER);
    }else {
        emit changePage(PAGE_ALARM_ADMIN);
    }
}

void HomeWindow::dataAnalysisPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_DATAANALYSIS_USER);
    }else {
        emit changePage(PAGE_DATAANALYSIS_ADMIN);
    }
}

void HomeWindow::systemLogPage()
{
    UserManager &userManager = UserManager::instance();
    QVariantMap user = userManager.getUserByUsername(m_userName);
    if(user.value("role").toString() == "user"){
        emit changePage(PAGE_SYSTEMLOG_USER);
    }else {
        emit changePage(PAGE_SYSTEMLOG_ADMIN);
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
