#include "adminrulemodify.h"
#include "ui_adminrulemodify.h"

#include <QMessageBox>

AdminRuleModify::AdminRuleModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminRuleModify)
{
    ui->setupUi(this);
    connect(ui->btnModifyOK,&QPushButton::clicked,this,&AdminRuleModify::modifyRuleInfo);
}

void AdminRuleModify::modifyByRuleId(int msg)
{
    m_ruleId = msg;
    AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
    QVariantMap rule = ruleManager.getRuleById(m_ruleId);
    ui->lineEditModifyID->setText(rule.value("device_id").toString());
    ui->lineEditModifyID->setClearButtonEnabled(true);
    ui->lineEditModifyDescription->setText(rule.value("description").toString());
    ui->lineEditModifyDescription->setClearButtonEnabled(true);
    ui->lineEditModifyCondition->setText(rule.value("condition").toString());
    ui->lineEditModifyCondition->setClearButtonEnabled(true);
    ui->lineEditModifyAction->setText(rule.value("action").toString());
    ui->lineEditModifyAction->setClearButtonEnabled(true);
}

void AdminRuleModify::modifyRuleInfo()
{
    AlarmRuleManager &ruleManager = AlarmRuleManager::instance();

    QVariantMap oldRule = ruleManager.getRuleById(m_ruleId);

    int newId = ui->lineEditModifyID->text().toInt();
    QString newDescription = ui->lineEditModifyDescription->text();
    QString newCondition = ui->lineEditModifyCondition->text();
    QString newAction = ui->lineEditModifyAction->text();

    QVariantMap update;
    if(oldRule.value("device_id").toInt() != newId){
        update["device_id"] = newId;
    }
    if(oldRule.value("description").toString() != newDescription){
        update["description"] = newDescription;
    }
    if(oldRule.value("condition").toString() != newCondition){
        update["condition"] = newCondition;
    }
    if(oldRule.value("action").toString() != newAction){
        update["action"] = newAction;
    }

    int ruleId = oldRule.value("rule_id").toInt();
    if(ruleManager.updateRuleById(ruleId,update)){
        QMessageBox::information(this,"成功","修改规则成功");
        emit modifyFinish("修改成功");
        this->close();
    }else {
        QMessageBox::warning(this,"失败","修改规则失败");
    }
}

AdminRuleModify::~AdminRuleModify()
{
    delete ui;
}
