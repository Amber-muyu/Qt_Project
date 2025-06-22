#include "alarmadmincontroller.h"
#include "ui_alarmadmincontroller.h"

#include <QMessageBox>

AlarmAdminController::AlarmAdminController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmAdminController)
{
    ui->setupUi(this);
    ui->tableViewRule->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewRule->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewRule->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableViewRecord->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewRecord->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewRecord->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->lineEditSelectRecord->setClearButtonEnabled(true);

    AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
    QList<QVariantMap> rules = ruleManager.getAllRules();
    initRuleInfoPage(rules);
    autoRefresh();

    AlarmRecordManager &recordManager = AlarmRecordManager::instance();
    QList<QVariantMap> records = recordManager.getAllRecords();
    initRecordInfoPage(records);

    connect(ui->btnAddRule,&QPushButton::clicked,this,&AlarmAdminController::addRulePage);
    connect(ui->btnDeleteRule,&QPushButton::clicked,this,&AlarmAdminController::deleteRule);
    connect(ui->btnModifyRule,&QPushButton::clicked,this,&AlarmAdminController::modifyRulePage);

    connect(ui->btnDeleteRecord,&QPushButton::clicked,this,&AlarmAdminController::deleteRecord);
    connect(ui->lineEditSelectRecord,&QLineEdit::textChanged,this,[=](const QString &text){

        m_isSearching = !text.trimmed().isEmpty();
        AlarmRecordManager &recordManager = AlarmRecordManager::instance();
        QList<QVariantMap> records;
        if (text.trimmed().isEmpty()) {
            records = recordManager.getAllRecords();
        } else {
            records = recordManager.searchRecords(text.trimmed());
        }
        initRecordInfoPage(records);
    });

    connect(ui->btnHandleRecord,&QPushButton::clicked,this,&AlarmAdminController::modifyRecordPage);
}

void AlarmAdminController::initRuleInfoPage(const QList<QVariantMap> &rules)
{
    QStringList headers = {"序号","设备ID","描述","触发条件","通知方式"};
    QStringList fields  = {"rule_id","device_id","description","condition","action"};

    if (!m_modelRule) {
        m_modelRule = new QStandardItemModel(this);
        ui->tableViewRule->setModel(m_modelRule);             // 只setModel 一次
    }

    m_modelRule->clear();
    m_modelRule->setRowCount(rules.size());
    m_modelRule->setColumnCount(headers.size());
    m_modelRule->setHorizontalHeaderLabels(headers);

    for(int row=0; row<rules.size(); ++row){
        const QVariantMap &rule = rules.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(rule.value(key).toString());
            m_modelRule->setItem(row,col,item);
        }
    }
}

void AlarmAdminController::initRecordInfoPage(const QList<QVariantMap> &records)
{
    QStringList headers = {"序号","设备ID","警告触发时间","警告内容","处理状态","处理备注"};
    QStringList fields  = {"alarm_id","device_id","timestamp","content","status","note"};

    if (!m_modelRecord) {
        m_modelRecord = new QStandardItemModel(this);
        ui->tableViewRecord->setModel(m_modelRecord);             // 只setModel 一次
    }

    m_modelRecord->clear();
    m_modelRecord->setRowCount(records.size());
    m_modelRecord->setColumnCount(headers.size());
    m_modelRecord->setHorizontalHeaderLabels(headers);

    for(int row=0; row<records.size(); ++row){
        const QVariantMap &record = records.at(row);
        for(int col=0; col<fields.size(); ++col){
            QString key=fields.at(col);
            QStandardItem *item = new QStandardItem(record.value(key).toString());
            m_modelRecord->setItem(row,col,item);
        }
    }
}

void AlarmAdminController::addRulePage()
{
    m_adminRuleAdd = new AdminRuleAdd;
    m_adminRuleAdd->setAttribute(Qt::WA_ShowModal);

    connect(m_adminRuleAdd,&AdminRuleAdd::addFinish,this,[=](){
        AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
        QList<QVariantMap> rules = ruleManager.getAllRules();
        initRuleInfoPage(rules);
    });

    m_adminRuleAdd->show();
}

void AlarmAdminController::deleteRule()
{
    int deleteRow = ui->tableViewRule->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中规则无法删除");
        return;
    }
    int deviceId = m_modelRule->item(deleteRow, 1)->text().toInt();
    QString description = m_modelRule->item(deleteRow, 2)->text();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除设备 %1 的 %2 规则吗？").arg(deviceId).arg(description),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        int deleteId = m_modelRule->item(deleteRow,0)->text().toInt();
        AlarmRuleManager &deviceManager =AlarmRuleManager::instance();
        if(deviceManager.deleteRule(deleteId)){
            QMessageBox::information(this,"成功","删除成功");
            QList<QVariantMap> devices = deviceManager.getAllRules();
            initRuleInfoPage(devices);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

void AlarmAdminController::modifyRulePage()
{
    m_adminRuleModify = new AdminRuleModify;
    m_adminRuleModify->setAttribute(Qt::WA_ShowModal);

    int modifyRow = ui->tableViewRule->currentIndex().row();
    if(modifyRow<0){
        QMessageBox::warning(this,"信息","未选中无法修改");
        return;
    }else {
        int modifyRuleId = m_modelRule->item(modifyRow,0)->text().toInt();
        connect(this,&AlarmAdminController::sendModifyRuleInfo,m_adminRuleModify,&AdminRuleModify::modifyByRuleId);
        emit sendModifyRuleInfo(modifyRuleId);
    }

    connect(m_adminRuleModify,&AdminRuleModify::modifyFinish,this,[=](){
        AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
        QList<QVariantMap> rules = ruleManager.getAllRules();
        initRuleInfoPage(rules);
    });

    m_adminRuleModify->show();
}

void AlarmAdminController::deleteRecord()
{
    int deleteRow = ui->tableViewRecord->currentIndex().row();
    if(deleteRow<0){
        QMessageBox::warning(this,"提示","未选中记录无法删除");
        return;
    }
    int deviceId = m_modelRecord->item(deleteRow, 1)->text().toInt();
    QString content = m_modelRecord->item(deleteRow, 3)->text();
    int ret = QMessageBox::question(
                this,
                "确认删除",
                QString("确定要删除设备 %1 的 %2 警告内容吗").arg(deviceId).arg(content),
                QMessageBox::Yes | QMessageBox::No,
                QMessageBox::No
                );
    if (ret == QMessageBox::Yes) {
        int deleteId = m_modelRecord->item(deleteRow,0)->text().toInt();
        AlarmRecordManager &recordManager =AlarmRecordManager::instance();
        if(recordManager.deleteRecord(deleteId)){
            QMessageBox::information(this,"成功","删除成功");
            QList<QVariantMap> records = recordManager.getAllRecords();
            initRecordInfoPage(records);
        }else {
            QMessageBox::warning(this,"失败","删除失败");
        }
    }
}

void AlarmAdminController::modifyRecordPage()
{
    int modifyRow = ui->tableViewRecord->currentIndex().row();
    if(modifyRow<0){
        QMessageBox::warning(this,"信息","未选中无法修改");
        return;
    }else {
        int modifyRecordId = m_modelRecord->item(modifyRow,0)->text().toInt();
        AlarmRecordManager &recordManager = AlarmRecordManager::instance();
        QVariantMap oldRecord = recordManager.getRecordById(modifyRecordId);

        QString newStatus = "HANDLED";
        QVariantMap update;
        if(oldRecord.value("status").toString() == newStatus){
            QMessageBox::warning(this,"失败","已处理，无法再操作");
            return;
        }
        update["status"] = newStatus;
        int alarm_id = oldRecord.value("alarm_id").toInt();
        if(recordManager.updateRecordById(alarm_id,update)){
            QMessageBox::information(this,"成功","已处理");
            QList<QVariantMap> records = recordManager.getAllRecords();
            initRecordInfoPage(records);
        }else {
            QMessageBox::warning(this,"失败","操作失败");
        }
    }
}

void AlarmAdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
            QList<QVariantMap> rules = ruleManager.getAllRules();
            AlarmRecordManager &recordManager = AlarmRecordManager::instance();
            QList<QVariantMap> records = recordManager.getAllRecords();
            initRuleInfoPage(rules);
            initRecordInfoPage(records);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

AlarmAdminController::~AlarmAdminController()
{
    delete ui;
}
