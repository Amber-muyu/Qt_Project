#include "deviceusercontroller.h"
#include "ui_deviceusercontroller.h"

DeviceUserController::DeviceUserController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceUserController)
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
}

void DeviceUserController::initDeviceInfoPage(const QList<QVariantMap>& devices)
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

void DeviceUserController::autoRefresh()
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

DeviceUserController::~DeviceUserController()
{
    delete ui;
}
