#include "statusbar.h"
#include "ui_statusbar.h"

StatusBar::StatusBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusBar)
{
    ui->setupUi(this);
    m_timer = new QTimer;
    connect(m_timer,&QTimer::timeout,this,&StatusBar::clearMessage);
}

void StatusBar::receiveMessage(const QString &msg)
{
    ui->labelStatusBar->setText(msg);
    m_timer->start(3000);   //3秒发送一个timeout信号
}

void StatusBar::clearMessage()
{
    ui->labelStatusBar->clear();
}

StatusBar::~StatusBar()
{
    delete ui;
}
