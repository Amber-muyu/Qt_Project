#include "dataadmincontroller.h"
#include "ui_dataadmincontroller.h"

#include <QMessageBox>

DataAdminController::DataAdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataAdminController)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->dateTimeEditFrom->setDate(QDate::currentDate());
    ui->dateTimeEditFrom->setCalendarPopup(true);
    ui->dateTimeEditTo->setDate(QDate::currentDate());
    ui->dateTimeEditTo->setCalendarPopup(true);

    DataManager &dataManager = DataManager::instance();
    QList<QVariantMap> data = dataManager.getAllData();
    initDataInfoPage(data);
    autoRefresh();

    connect(ui->btnAddData,&QPushButton::clicked,this,&DataAdminController::addData);
    connect(ui->btnDeleteData,&QPushButton::clicked,this,&DataAdminController::deleteData);
    connect(ui->btnSearch,&QPushButton::clicked,this,&DataAdminController::searchData);
    connect(ui->btnReset,&QPushButton::clicked,this,&DataAdminController::resetData);
    connect(ui->btnDataExport,&QPushButton::clicked,this,&DataAdminController::exportData);
    connect(ui->btnRealShowData,&QPushButton::clicked,this,&DataAdminController::realShowData);
}

void DataAdminController::initDataInfoPage(const QList<QVariantMap> &data)
{
    QStringList headers = {"序号","设备ID","时间","温度数据","湿度数据","光照数据","二氧化碳浓度","气压"};
    QStringList fields  = {"data_id","device_id","timestamp","temperature","humidity","light","co2","pressure"};

    if (!m_model) {
        m_model = new QStandardItemModel(this);
        ui->tableView->setModel(m_model);             // 只setModel 一次
    }

    m_model->clear();
    m_model->setRowCount(data.size());
    m_model->setColumnCount(headers.size());
    m_model->setHorizontalHeaderLabels(headers);

    for(int row=0; row<data.size(); ++row){
        const QVariantMap &singleData = data.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(singleData.value(key).toString());
            m_model->setItem(row,col,item);
        }
    }
}

void DataAdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            DataManager &deviceManager = DataManager::instance();
            QList<QVariantMap> data = deviceManager.getAllData();
            initDataInfoPage(data);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

void DataAdminController::addData()
{
    if (m_serialPort) {
        m_serialPort->raise();
        return;
    }

    m_serialPort = new SerialPort();
    m_serialPort->setAttribute(Qt::WA_DeleteOnClose, false);
    m_serialPort->setWindowTitle("串口通信");

    //数据新增后立即刷新
    connect(m_serialPort,&SerialPort::addFinish,this,[=](){
        DataManager &deviceManager = DataManager::instance();
        QList<QVariantMap> devices = deviceManager.getAllData();
        initDataInfoPage(devices);
    });

    connect(m_serialPort, &SerialPort::dataReceived, this, &DataAdminController::onSerialDataReceived);

    // 连接窗口关闭信号
    connect(m_serialPort, &SerialPort::aboutToClose, this, [this]() {
        m_serialPort->deleteLater();
        m_serialPort = nullptr;
    });

    m_serialPort->show();
}

void DataAdminController::deleteData()
{
    int deleteRow = ui->tableView->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中数据无法删除");
        return;
    }
    int deleteId = m_model->item(deleteRow,0)->text().toInt();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除数据 %1 吗？").arg(deleteId),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        DataManager &dataManager =DataManager::instance();
        if(dataManager.deleteData(deleteId)){
            QMessageBox::information(this,"成功","删除成功");
            QList<QVariantMap> devices = dataManager.getAllData();
            initDataInfoPage(devices);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

void DataAdminController::searchData()
{
    QString startTime = ui->dateTimeEditFrom->dateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString endTime = ui->dateTimeEditTo->dateTime().toString("yyyy-MM-dd HH:mm:ss");

    if(startTime>endTime){
        QMessageBox::warning(this,"警告","结束时间不能大于起始时间");
        return;
    }
    m_isSearching = true;
    DataManager &dataManager = DataManager::instance();
    QList<QVariantMap> data = dataManager.getDataByTimeRange(startTime,endTime);
    initDataInfoPage(data);
}

void DataAdminController::resetData()
{
    m_isSearching = false;
    ui->dateTimeEditFrom->setDateTime(QDateTime(QDate::currentDate(),QTime(0,0)));
    ui->dateTimeEditTo->setDateTime(QDateTime(QDate::currentDate(),QTime(0,0)));
    DataManager &dataManager = DataManager::instance();
    QList<QVariantMap> data = dataManager.getAllData();
    initDataInfoPage(data);
}

void DataAdminController::exportData()
{
    /* 1. 取全部数据 --------------------------------------------------- */
    QList<QVariantMap> data = DataManager::instance().getAllData();
    if (data.isEmpty()) {
        QMessageBox::warning(this, "提示", "没有数据可导出！");
        return;
    }

    /* 2. 让用户选择保存路径 ------------------------------------------- */
    // 初始文件名：Documents/data_export.xlsx
    QString initPath = QStandardPaths::writableLocation(
                QStandardPaths::DocumentsLocation)
            + "/data_export.xlsx";

    QString selectedFilter;
    QString filePath = QFileDialog::getSaveFileName(
                this,
                "数据导出",
                initPath,
                "Excel 文件 (*.xlsx);;CSV 文件 (*.csv)",
                &selectedFilter);                        // <<--- 取过滤器
    if (filePath.isEmpty()) return;

    /* 3. 若无扩展名 → 根据过滤器自动补齐 ------------------------------- */
    if (QFileInfo(filePath).suffix().isEmpty()) {
        if (selectedFilter.startsWith("Excel"))
            filePath += ".xlsx";
        else
            filePath += ".csv";
    }

    /* 4. 根据最终后缀决定导出格式 -------------------------------------- */
    QString ext = QFileInfo(filePath).suffix().toLower();
    bool ok = false;

    if (ext == "xlsx") {
        ok = DataManager::instance().exportToExcel(data, filePath);
    } else if (ext == "csv") {
        ok = DataManager::instance().exportToCsv(data, filePath);
    } else {
        QMessageBox::critical(this, "错误", "不支持的导出格式: ." + ext);
        return;
    }

    /* 5. 结果提示 ------------------------------------------------------ */
    if (ok)
        QMessageBox::information(this, "导出成功",
                                 "数据已导出到:\n" + QDir::toNativeSeparators(filePath));
    else
        QMessageBox::critical(this, "导出失败", "写入文件时发生错误！");
}

void DataAdminController::realShowData()
{
    if (!m_realTimeChar) {
        m_realTimeChar = new RealTimeChart();
    }
    m_realTimeChar->show();
    m_realTimeChar->raise();
    m_realTimeChar->activateWindow();
    m_realTimeChar->setWindowTitle("实时数据显示");

}

void DataAdminController::onSerialDataReceived(const QVariantMap &data) {
    if (m_realTimeChar) {
        m_realTimeChar->updateCharts(data);
    }
}

void DataAdminController::closeSerialPort()
{
    if (m_serialPort) {
        m_serialPort->disconnect();
        m_serialPort->close();
        m_serialPort->deleteLater();
        m_serialPort = nullptr;
    }
}

DataAdminController::~DataAdminController()
{
    closeSerialPort();
    delete ui;
}
