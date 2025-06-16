#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : BaseFrame(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    m_titleBar = new TitleBar;
    m_statusBar = new StatusBar;
    m_loginWindow = new LoginWindow;
    m_homeWindow = new HomeWindow;
    m_registerWindow = new RegisterWindow;
    m_resetPasswdWindow = new ResetPasswdWindow;

    m_stackedLayout = new QStackedLayout(this);

    ui->titleBarLayout->addWidget(m_titleBar);
    ui->statusBarLayout->addWidget(m_statusBar);
    ui->centerLayout->addLayout(m_stackedLayout);

    m_stackedLayout->addWidget(m_loginWindow);
    m_stackedLayout->addWidget(m_homeWindow);
    m_stackedLayout->addWidget(m_registerWindow);
    m_stackedLayout->addWidget(m_resetPasswdWindow);

    //标题右上角三个按钮
    connect(m_titleBar,&TitleBar::signalMin,this,&MainWindow::showMinimized);
    connect(m_titleBar,&TitleBar::signalIsMax,this,&MainWindow::showIsMax);
    connect(m_titleBar,&TitleBar::signalClose,this,&MainWindow::close);

    //状态栏信息显示
    connect(m_loginWindow,&LoginWindow::sendMessage,m_statusBar,&StatusBar::receiveMessage);
    connect(m_registerWindow,&RegisterWindow::sendMessage,m_statusBar,&StatusBar::receiveMessage);

    //页面切换
    connect(m_loginWindow,&LoginWindow::display,m_stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(m_registerWindow,&RegisterWindow::display,m_stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(m_resetPasswdWindow,&ResetPasswdWindow::display,m_stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(m_homeWindow,&HomeWindow::display,m_stackedLayout,&QStackedLayout::setCurrentIndex);
}

void MainWindow::showIsMax()
{
    if(!isMaximized()){
        this->showMaximized();
    }else{
        this->showNormal();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
