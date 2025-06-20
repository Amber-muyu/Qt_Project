#include "datausercontroller.h"
#include "ui_datausercontroller.h"

DataUserController::DataUserController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataUserController)
{
    ui->setupUi(this);
}

DataUserController::~DataUserController()
{
    delete ui;
}
