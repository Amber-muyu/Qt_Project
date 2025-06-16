#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

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
