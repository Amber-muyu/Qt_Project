#include "deviceadmincontroller.h"
#include "ui_deviceadmincontroller.h"

#include <QMessageBox>
DeviceAdminController::DeviceAdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceAdminController)
{
    ui->setupUi(this);
    ui->lineEditSelectDevice->setClearButtonEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    DeviceManager &deviceManager = DeviceManager::instance();
    QList<QVariantMap> devices = deviceManager.getAllDevices();

    initDeviceInfoPage(devices);
    autoRefresh();

    connect(ui->lineEditSelectDevice,&QLineEdit::textChanged,this,[=](const QString &text){

        m_isSearching = !text.trimmed().isEmpty();
        DeviceManager &deviceManager = DeviceManager::instance();
        QList<QVariantMap> devices;
        if (text.trimmed().isEmpty()) {
            devices = deviceManager.getAllDevices();
        } else {
            devices = deviceManager.searchDevices(text.trimmed());
        }
        initDeviceInfoPage(devices);
    });

    connect(ui->btnAddDevice,&QPushButton::clicked,this,&DeviceAdminController::addDevice);
    connect(ui->btnModifyDevice,&QPushButton::clicked,this,&DeviceAdminController::modifyDevice);
    connect(ui->btnDeleteDevice,&QPushButton::clicked,this,&DeviceAdminController::deleteDevice);
}

void DeviceAdminController::initDeviceInfoPage(const QList<QVariantMap>& devices)
{

    QStringList headers = {"序号","设备名","类型","设备安装位置","设备制造商","设备型号","设备状态","安装时间"};
    QStringList fields  = {"device_id","name","type","location","manufacturer","model","status","installation_date"};

    if (!m_model) {
        m_model = new QStandardItemModel(this);
        ui->tableView->setModel(m_model);             // 只setModel 一次
    }

    m_model->clear();
    m_model->setRowCount(devices.size());
    m_model->setColumnCount(headers.size());
    m_model->setHorizontalHeaderLabels(headers);

    for(int row=0; row<devices.size(); ++row){
        const QVariantMap &device = devices.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(device.value(key).toString());
            m_model->setItem(row,col,item);
        }
    }
}

void DeviceAdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            DeviceManager &deviceManager = DeviceManager::instance();
            QList<QVariantMap> devices = deviceManager.getAllDevices();
            initDeviceInfoPage(devices);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

void DeviceAdminController::addDevice()
{
    m_adminDeviceInfoAdd = new AdminDeviceInfoAdd;
    m_adminDeviceInfoAdd->setAttribute(Qt::WA_ShowModal);

    connect(m_adminDeviceInfoAdd,&AdminDeviceInfoAdd::addFinish,this,[=](){
        DeviceManager &userManager = DeviceManager::instance();
        QList<QVariantMap> devices = userManager.getAllDevices();
        initDeviceInfoPage(devices);
    });

    m_adminDeviceInfoAdd->show();
}

void DeviceAdminController::modifyDevice()
{
    m_adminDeviceInfoModify = new AdminDeviceInfoModify;
    m_adminDeviceInfoModify->setAttribute(Qt::WA_ShowModal);

    int modifyRow = ui->tableView->currentIndex().row();
    if(modifyRow<0){
        QMessageBox::warning(this,"信息","未选中无法修改");
        return;
    }else {
        int modifyDeviceId = m_model->item(modifyRow,0)->text().toInt();
        connect(this,&DeviceAdminController::sendModifyDeviceInfo,m_adminDeviceInfoModify,&AdminDeviceInfoModify::modifyByDeviceId);
        emit sendModifyDeviceInfo(modifyDeviceId);
    }

    connect(m_adminDeviceInfoModify,&AdminDeviceInfoModify::modifyFinish,this,[=](){
        DeviceManager &deviceManager = DeviceManager::instance();
        QList<QVariantMap> devices = deviceManager.getAllDevices();
        initDeviceInfoPage(devices);
    });

    m_adminDeviceInfoModify->show();
}

void DeviceAdminController::deleteDevice()
{
    int deleteRow = ui->tableView->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中设备无法删除");
        return;
    }
    QString name = m_model->item(deleteRow, 1)->text();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除设备 %1 吗？").arg(name),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        int deleteId = m_model->item(deleteRow,0)->text().toInt();
        DeviceManager &deviceManager =DeviceManager::instance();
        if(deviceManager.deleteDevice(deleteId)){
            QMessageBox::information(this,"成功","删除成功");
            QList<QVariantMap> devices = deviceManager.getAllDevices();
            initDeviceInfoPage(devices);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

DeviceAdminController::~DeviceAdminController()
{
    delete ui;
}
