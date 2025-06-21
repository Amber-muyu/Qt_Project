#include "alarmusercontroller.h"
#include "ui_alarmusercontroller.h"

AlarmUserController::AlarmUserController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmUserController)
{
    ui->setupUi(this);
}

AlarmUserController::~AlarmUserController()
{
    delete ui;
}
