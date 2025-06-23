#include "systemlogusercontroller.h"
#include "ui_systemlogusercontroller.h"

SystemLogUserController::SystemLogUserController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemLogUserController)
{
    ui->setupUi(this);
}

SystemLogUserController::~SystemLogUserController()
{
    delete ui;
}
