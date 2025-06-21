#include "adminruleadd.h"
#include "ui_adminruleadd.h"

#include <QMessageBox>

AdminRuleAdd::AdminRuleAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminRuleAdd)
{
    ui->setupUi(this);
    ui->lineEditAddID->setPlaceholderText("请输入设备ID");
    ui->lineEditAddID->setClearButtonEnabled(true);
    ui->lineEditAddDescription->setPlaceholderText("请输入描述");
    ui->lineEditAddDescription->setClearButtonEnabled(true);
    ui->lineEditAddCondition->setPlaceholderText("请输入触发条件");
    ui->lineEditAddCondition->setClearButtonEnabled(true);
    ui->lineEditAddAction->setPlaceholderText("请输入通知方式");
    ui->lineEditAddAction->setClearButtonEnabled(true);
    connect(ui->btnAddOK,&QPushButton::clicked,this,&AdminRuleAdd::addRuleInfo);
}

void AdminRuleAdd::addRuleInfo()
{
    AlarmRuleManager &ruleManager = AlarmRuleManager::instance();
    QVariantMap newRule;
    newRule["device_id"] = ui->lineEditAddID->text();
    newRule["descrption"] = ui->lineEditAddDescription->text();
    newRule["condition"] = ui->lineEditAddCondition->text();
    newRule["action"] = ui->lineEditAddAction->text();

    if(ruleManager.addRule(newRule)){
        QMessageBox::information(this,"成功","新增规则成功!");
        ui->lineEditAddID->clear();
        ui->lineEditAddDescription->clear();
        ui->lineEditAddCondition->clear();
        ui->lineEditAddAction->clear();
        emit addFinish("注册成功");
        this->close();
    }else {
        ui->lineEditAddID->clear();
        ui->lineEditAddDescription->clear();
        ui->lineEditAddCondition->clear();
        ui->lineEditAddAction->clear();
        QMessageBox::warning(this,"失败","新增规则失败!");
    }
}

AdminRuleAdd::~AdminRuleAdd()
{
    delete ui;
}
