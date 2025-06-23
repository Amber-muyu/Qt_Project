#include "systemlogadmincontroller.h"
#include "ui_systemlogadmincontroller.h"

#include <QMessageBox>
#include <QFileDialog>

SystemLogAdminController::SystemLogAdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemLogAdminController)
{
    ui->setupUi(this);
    ui->lineEditSelectLog->setClearButtonEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    SystemLogsManager &logManager = SystemLogsManager::instance();
    QList<QVariantMap> logs = logManager.getAllLogs();

    initLogInfoPage(logs);
    autoRefresh();

    connect(ui->lineEditSelectLog,&QLineEdit::textChanged,this,[=](const QString &text){

        m_isSearching = !text.trimmed().isEmpty();
        SystemLogsManager &logManager = SystemLogsManager::instance();
        QList<QVariantMap> logs;
        if (text.trimmed().isEmpty()) {
            logs = logManager.getAllLogs();
        } else {
            logs = logManager.searchLogs(text.trimmed());
        }
        initLogInfoPage(logs);
    });

    connect(ui->btnDeleteLog,&QPushButton::clicked,this,&SystemLogAdminController::deleteLog);
    connect(ui->btnExportLog,&QPushButton::clicked,this,&SystemLogAdminController::exportLog);
}

void SystemLogAdminController::initLogInfoPage(const QList<QVariantMap> &logs)
{
    QStringList headers = {"序号","日志时间","日志类型","日志等级","日志内容","用户ID","设备ID"};
    QStringList fields  = {"log_id","timestamp","log_type","log_level","content","user_id","device_id"};

    if (!m_model) {
        m_model = new QStandardItemModel(this);
        ui->tableView->setModel(m_model);             // 只setModel 一次
    }

    m_model->clear();
    m_model->setRowCount(logs.size());
    m_model->setColumnCount(headers.size());
    m_model->setHorizontalHeaderLabels(headers);

    for(int row=0; row<logs.size(); ++row){
        const QVariantMap &log = logs.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(log.value(key).toString());
            m_model->setItem(row,col,item);
        }
    }
}

void SystemLogAdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            SystemLogsManager &logManager = SystemLogsManager::instance();
            QList<QVariantMap> logs = logManager.getAllLogs();
            initLogInfoPage(logs);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

void SystemLogAdminController::deleteLog()
{
    int deleteRow = ui->tableView->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中日志无法删除");
        return;
    }
    int name = m_model->item(deleteRow, 0)->text().toInt();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除日志 %1 吗？").arg(name),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        int deleteId = m_model->item(deleteRow,0)->text().toInt();
        SystemLogsManager &logManager = SystemLogsManager::instance();
        if(logManager.deleteLog(deleteId)){
            QMessageBox::information(this,"成功","删除成功");
            QList<QVariantMap> logs = logManager.getAllLogs();
            initLogInfoPage(logs);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

void SystemLogAdminController::exportLog()
{
    /* 1. 取全部数据 --------------------------------------------------- */
    QList<QVariantMap> data = SystemLogsManager::instance().getAllLogs();
    if (data.isEmpty()) {
        QMessageBox::warning(this, "提示", "没有数据可导出！");
        return;
    }

    /* 2. 让用户选择保存路径 ------------------------------------------- */
    // 初始文件名：Documents/log_export.xlsx
    QString initPath = QStandardPaths::writableLocation(
                QStandardPaths::DocumentsLocation)
            + "/log_export.xlsx";

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
        ok = SystemLogsManager::instance().exportToExcel(data, filePath);
    } else if (ext == "csv") {
        ok = SystemLogsManager::instance().exportToCsv(data, filePath);
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

SystemLogAdminController::~SystemLogAdminController()
{
    delete ui;
}
