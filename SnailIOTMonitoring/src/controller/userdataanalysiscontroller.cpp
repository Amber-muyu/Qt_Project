#include "userdataanalysiscontroller.h"
#include "ui_userdataanalysiscontroller.h"

UserDataAnalysisController::UserDataAnalysisController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserDataAnalysisController)
{
    ui->setupUi(this);
}

UserDataAnalysisController::~UserDataAnalysisController()
{
    delete ui;
}
