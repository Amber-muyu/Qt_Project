#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

    ui->btnMin->setObjectName("btnMin");
    ui->btnMax->setObjectName("btnMax");
    ui->btnClose->setObjectName("btnClose");

    connect(ui->btnMin,&QPushButton::clicked,this,[=]{
        emit signalMin();
    });

    connect(ui->btnMax,&QPushButton::clicked,this,[=]{
        emit signalIsMax();
    });

    connect(ui->btnClose,&QPushButton::clicked,this,[=]{
        emit signalClose();
    });
}

TitleBar::~TitleBar()
{
    delete ui;
}
