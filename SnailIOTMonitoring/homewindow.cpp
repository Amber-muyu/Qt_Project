#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    connect(ui->btnLogout,&QPushButton::clicked,this,&HomeWindow::logoutReturnPage);
}

void HomeWindow::logoutReturnPage()
{
    emit display(0);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
