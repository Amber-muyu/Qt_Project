#include "admindeviceinfoadd.h"
#include "ui_admindeviceinfoadd.h"

#include <QMessageBox>

AdminDeviceInfoAdd::AdminDeviceInfoAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminDeviceInfoAdd)
{
    ui->setupUi(this);
    ui->lineEditAddName->setPlaceholderText("请输入设备名");
    ui->lineEditAddName->setClearButtonEnabled(true);
    ui->lineEditAddType->setPlaceholderText("请输入设备类型");
    ui->lineEditAddType->setClearButtonEnabled(true);
    ui->lineEditAddLocation->setPlaceholderText("请输入设备安装位置");
    ui->lineEditAddLocation->setClearButtonEnabled(true);
    ui->lineEditAddManufacturer->setPlaceholderText("请输入设备制造商");
    ui->lineEditAddManufacturer->setClearButtonEnabled(true);
    ui->lineEditAddModel->setPlaceholderText("请输入设备型号");
    ui->lineEditAddModel->setClearButtonEnabled(true);
    connect(ui->btnAddOK,&QPushButton::clicked,this,&AdminDeviceInfoAdd::addDeviceInfo);
}

void AdminDeviceInfoAdd::addDeviceInfo()
{
    DeviceManager &deviceManager = DeviceManager::instance();
    QVariantMap newDevice;
    newDevice["name"] = ui->lineEditAddName->text();
    newDevice["type"] = ui->lineEditAddType->text();
    newDevice["location"] = ui->lineEditAddLocation->text();
    newDevice["manufacturer"] = ui->lineEditAddManufacturer->text();
    newDevice["model"] = ui->lineEditAddModel->text();

    if(deviceManager.addDevice(newDevice)){
        QMessageBox::information(this,"成功","新增设备成功!");
        ui->lineEditAddName->clear();
        ui->lineEditAddType->clear();
        ui->lineEditAddLocation->clear();
        ui->lineEditAddManufacturer->clear();
        ui->lineEditAddModel->clear();
        emit addFinish("注册成功");
        this->close();
    }else {
        ui->lineEditAddName->clear();
        ui->lineEditAddType->clear();
        ui->lineEditAddLocation->clear();
        ui->lineEditAddManufacturer->clear();
        ui->lineEditAddModel->clear();
        QMessageBox::warning(this,"失败","新增设备失败!");
    }
}

AdminDeviceInfoAdd::~AdminDeviceInfoAdd()
{
    delete ui;
}
