#include "admindeviceinfomodify.h"
#include "ui_admindeviceinfomodify.h"

#include <QMessageBox>

AdminDeviceInfoModify::AdminDeviceInfoModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminDeviceInfoModify)
{
    ui->setupUi(this);
    connect(ui->btnInfoModifyOK,&QPushButton::clicked,this,&AdminDeviceInfoModify::modifyDeviceInfo);
}

void AdminDeviceInfoModify::modifyByDeviceId(int msg)
{
    m_deviceId = msg;
    DeviceManager &deviceManager = DeviceManager::instance();
    QVariantMap device = deviceManager.getDeviceById(m_deviceId);
    ui->lineEditModifyDeviceName->setText(device.value("name").toString());
    ui->lineEditModifyDeviceName->setClearButtonEnabled(true);
    ui->lineEditModifyType->setText(device.value("type").toString());
    ui->lineEditModifyType->setClearButtonEnabled(true);
    ui->lineEditModifyLocation->setText(device.value("location").toString());
    ui->lineEditModifyLocation->setClearButtonEnabled(true);
    ui->lineEditModifyManufacturer->setText(device.value("manufacturer").toString());
    ui->lineEditModifyManufacturer->setClearButtonEnabled(true);
    ui->lineEditModifyModel->setText(device.value("model").toString());
    ui->lineEditModifyModel->setClearButtonEnabled(true);
    ui->lineEditModifyStatus->setText(device.value("status").toString());
    ui->lineEditModifyStatus->setClearButtonEnabled(true);
}

void AdminDeviceInfoModify::modifyDeviceInfo()
{
    DeviceManager &deviceManager = DeviceManager::instance();

    QVariantMap oldDevice = deviceManager.getDeviceById(m_deviceId);

    QString newName = ui->lineEditModifyDeviceName->text();
    QString newType = ui->lineEditModifyType->text();
    QString newLocation = ui->lineEditModifyLocation->text();
    QString newManufacturer = ui->lineEditModifyManufacturer->text();
    QString newModel = ui->lineEditModifyModel->text();
    QString newStatus = ui->lineEditModifyStatus->text();

    QVariantMap update;
    if(oldDevice.value("username").toString() != newName){
        update["name"] = newName;
    }
    if(oldDevice.value("type").toString() != newType){
        update["type"] = newType;
    }
    if(oldDevice.value("location").toString() != newLocation){
        update["location"] = newLocation;
    }
    if(oldDevice.value("manufacturer").toString() != newManufacturer){
        update["manufacturer"] = newManufacturer;
    }
    if (oldDevice.value("model").toString() != newModel) {
        update["model"] = newModel;
    }
    if(oldDevice.value("status").toString() != newStatus){
        update["status"] = newStatus;
    }

    int deviceId = oldDevice.value("device_id").toInt();
    if(deviceManager.updateDeviceById(deviceId,update)){
        QMessageBox::information(this,"成功","修改设备信息成功");
        emit modifyFinish("修改成功");
        this->close();
    }else {
        QMessageBox::warning(this,"失败","修改设备信息失败");
    }
}

AdminDeviceInfoModify::~AdminDeviceInfoModify()
{
    delete ui;
}
