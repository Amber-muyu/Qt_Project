#include "alarmadmincontroller.h"
#include "ui_alarmadmincontroller.h"

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

    connect(ui->btnAddRule,&QPushButton::clicked,this,&AlarmAdminController::addRulePage);
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

void AlarmAdminController::autoRefresh()
{
    QTimer *timer = new QTimer(this);  // this确保随窗口销毁
    connect(timer, &QTimer::timeout, this,[=](){
        if (!m_isSearching) {
            AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
            QList<QVariantMap> rules = ruleManager.getAllRules();
            initRuleInfoPage(rules);
        }
    });
    timer->start(10000);  // 每10秒刷新一次
}

AlarmAdminController::~AlarmAdminController()
{
    delete ui;
}
