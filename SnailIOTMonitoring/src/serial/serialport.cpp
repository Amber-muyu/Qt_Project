#include "serialport.h"
#include "ui_serialport.h"

#include <QMessageBox>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog","N/A");

SerialPort::SerialPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPort)
{
    ui->setupUi(this);
    serialPortConfig();

    m_pSerialPort = new QSerialPort(this);
    m_isOpen = false;

    connect(ui->btnOpen,&QPushButton::clicked,this,&SerialPort::onOpenPort);
    connect(ui->btnSend, &QPushButton::clicked, this, &SerialPort::sendData);
    connect(m_pSerialPort, &QSerialPort::errorOccurred, this, &SerialPort::handleError);
}

void SerialPort::serialPortConfig()
{
    //端口号配置
    QString description;
    QString manufacturer;
    QString serialNumber;

    //获取可以用的串口
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    //输入当前系统可以用的串口个数
    qDebug() << "Total numbers of ports:" << serialPortInfos.count();

    //将所有可以使用的串口设备添加到comBox中
    for(const auto &serialPortInfo : serialPortInfos) {
        QStringList list;
        description = serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();

        list << serialPortInfo.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << serialPortInfo.systemLocation()
             << (serialPortInfo.vendorIdentifier() ? QString::number(serialPortInfo.vendorIdentifier(),16) : blankString)
             << (serialPortInfo.productIdentifier() ? QString::number(serialPortInfo.productIdentifier(),16) : blankString);

        ui->comboBoxPort->addItem(list.first(),list);
    }
    //配置波特率
    ui->comboBoxBaudRate->addItem(QStringLiteral("9600"),QSerialPort::Baud9600);
    ui->comboBoxBaudRate->addItem(QStringLiteral("19200"),QSerialPort::Baud19200);
    ui->comboBoxBaudRate->addItem(QStringLiteral("38400"),QSerialPort::Baud38400);
    ui->comboBoxBaudRate->addItem(QStringLiteral("57600"),QSerialPort::Baud57600);
    ui->comboBoxBaudRate->addItem(QStringLiteral("115200"),QSerialPort::Baud115200);
    //数据位
    ui->comboBoxDatabits->addItem("5",QSerialPort::Data5);
    ui->comboBoxDatabits->addItem("6",QSerialPort::Data6);
    ui->comboBoxDatabits->addItem("7",QSerialPort::Data7);
    ui->comboBoxDatabits->addItem("8",QSerialPort::Data8);
    //校验位
    ui->comboBoxParity->addItem("NONE",QSerialPort::NoParity);
    ui->comboBoxParity->addItem("EVEN",QSerialPort::EvenParity);
    ui->comboBoxParity->addItem("ODD",QSerialPort::OddParity);
    ui->comboBoxParity->addItem("SPACE",QSerialPort::SpaceParity);
    ui->comboBoxParity->addItem("MARK",QSerialPort::MarkParity);
    //停止位
    ui->comboBoxStopbit->addItem("1",QSerialPort::OneStop);
    ui->comboBoxStopbit->addItem("1.5",QSerialPort::OneAndHalfStop);
    ui->comboBoxStopbit->addItem("2",QSerialPort::TwoStop);
    //流控制
    ui->comboBoxFlowctr->addItem("NONE",QSerialPort::NoFlowControl);
    ui->comboBoxFlowctr->addItem("Hardware",QSerialPort::HardwareControl);
    ui->comboBoxFlowctr->addItem("Software",QSerialPort::SoftwareControl);
}

void SerialPort::onOpenPort()
{
    if(!m_isOpen) {
        //设置串口属性
        m_pSerialPort->setPortName(ui->comboBoxPort->currentText());
        m_pSerialPort->setBaudRate(ui->comboBoxBaudRate->currentText().toInt());
        m_pSerialPort->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboBoxDatabits->currentData().toInt()));
        m_pSerialPort->setParity(static_cast<QSerialPort::Parity>(ui->comboBoxParity->currentData().toInt()));
        m_pSerialPort->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboBoxStopbit->currentData().toInt()));
        m_pSerialPort->setFlowControl(static_cast<QSerialPort::FlowControl>(ui->comboBoxFlowctr->currentData().toInt()));
        //只有参数设置完以后才能打开串口
        if(m_pSerialPort->open(QIODevice::ReadWrite)){
            //串口打开
            ui->btnOpen->setText("关闭串口");
            m_isOpen = true;
            setWidgetsEnabled(false);
            connect(m_pSerialPort,&QSerialPort::readyRead,this,&SerialPort::readData);
            qDebug() << "串口打开成功:" << m_pSerialPort->portName();
        } else {
            QMessageBox::critical(this, "发送失败", "未找到正确的串口");
            qDebug() << "串口打开失败: \"未找到正确的串口\"";
        }
    }else {
        if(m_pSerialPort->isOpen()) {
            m_pSerialPort->close();
        }
        m_isOpen = false;
        ui->btnOpen->setText("打开串口");
        setWidgetsEnabled(true);
        qDebug() << "串口已关闭";
    }
}

void SerialPort::readData(){
    QByteArray data = m_pSerialPort->readAll();
    if (data.isEmpty()) {
        return;
    }
    ui->receiveArea->append(QString::fromUtf8(data));

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "json解析失败";
        return;
    }

    DataManager &dataManager = DataManager::instance();
    AlarmRuleManager &ruleManager = AlarmRuleManager::instance();

    // 获取所有告警规则
    QList<QVariantMap> rules = ruleManager.getAllRules();
    if (rules.isEmpty()) {
        qDebug() << "没有可用的告警规则";
    }
    // 创建JS引擎用于条件评估
    QJSEngine jsEngine;

    // 判断是对象还是数组
    if (jsonDoc.isObject()) {
        QVariantMap dataMap = jsonDoc.object().toVariantMap();
        if(dataManager.addData(dataMap)){
            qDebug() << "数据接受成功";
            emit addFinish("接受成功");
            emit dataReceived(dataMap);

            // 检查告警规则
            checkAlarmRules(dataMap, rules, jsEngine);

        }else {
            qDebug() << "数据接受失败";
            return;
        }
    } else if (jsonDoc.isArray()) {
        QJsonArray arr = jsonDoc.array();
        for (const QJsonValue &val : arr) {
            if (val.isObject()) {
                QVariantMap dataMap = val.toObject().toVariantMap();
                if(dataManager.addData(dataMap)){
                    qDebug() << "数据接受成功";
                    emit addFinish("接受成功");
                    emit dataReceived(dataMap);

                    // 检查警告规则
                    checkAlarmRules(dataMap, rules, jsEngine);
                }else {
                    qDebug() << "数据接受失败";
                    return;
                }
            }
        }
    }
}

// 检查数据是否触发告警规则
void SerialPort::checkAlarmRules(const QVariantMap &dataMap,const QList<QVariantMap> &rules,QJSEngine &jsEngine)
{
    AlarmRecordManager &recordManager = AlarmRecordManager::instance();

    // 获取设备ID（假设数据中有device_id字段）
    int deviceId = dataMap.value("device_id", -1).toInt();
    if (deviceId <= 0) {
        qDebug() << "无效的设备ID，无法检查告警规则";
        return;
    }

    // 将数据字段注入JS引擎
    QJSValue jsData = jsEngine.newObject();
    for (auto it = dataMap.constBegin(); it != dataMap.constEnd(); ++it) {
        // 将QVariant转换为JS值
        QVariant value = it.value();
        if (value.type() == QVariant::Double || value.type() == QVariant::Int) {
            jsData.setProperty(it.key(), value.toDouble());
        } else if (value.type() == QVariant::String) {
            jsData.setProperty(it.key(), value.toString());
        } else if (value.type() == QVariant::Bool) {
            jsData.setProperty(it.key(), value.toBool());
        } else {
            jsData.setProperty(it.key(), value.toString());
        }
    }

    // 将数据对象设置为全局变量
    jsEngine.globalObject().setProperty("data", jsData);

    // 遍历所有规则
    for (const QVariantMap &rule : rules) {
        // 检查规则是否适用于当前设备
        int ruleDeviceId = rule.value("device_id", -1).toInt();
        if (ruleDeviceId != deviceId) {
            continue;
        }

        QString condition = rule.value("condition").toString();
        if (condition.isEmpty()) {
            continue;
        }

        try {
            // 评估条件表达式 - 现在通过 data.temperature 访问
            QJSValue result = jsEngine.evaluate(condition);

            if (result.isError()) {
                qWarning() << "规则条件评估错误:" << result.toString()
                           << "规则ID:" << rule.value("rule_id").toInt()
                           << "条件:" << condition;
                continue;
            }

            if (result.toBool()) {
                // 触发告警，创建告警记录
                QVariantMap alarmRecord;
                alarmRecord["device_id"] = deviceId;
                alarmRecord["timestamp"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
                alarmRecord["content"] = rule.value("description").toString() +
                        " -- 触发值: " + QString::number(dataMap.value("temperature").toDouble());
                alarmRecord["status"] = "UNHANDLED";
                alarmRecord["note"] = "";

                // 添加告警记录
                if (recordManager.addRecord(alarmRecord)) {
                    qDebug() << "告警触发:" << alarmRecord["content"].toString();
                    emit alarmTriggered(alarmRecord);
                } else {
                    qWarning() << "告警记录添加失败";
                }
            }
        } catch (...) {
            qWarning() << "规则条件执行异常:" << condition;
        }
    }
}

void SerialPort::sendData()
{
    if (!m_isOpen || !m_pSerialPort->isOpen()) {
        QMessageBox::warning(this, "提示", "请先打开串口！");
        ui->sendArea->clear();
        return;
    }

    QString text = ui->sendArea->toPlainText();
    if (text.trimmed().isEmpty()){
        return;
    }

    QByteArray outData = text.toUtf8();
    outData.append('\r');
    outData.append('\n');

    /* 5) 真正写入串口 */
    qint64 written = m_pSerialPort->write(outData);
    if (written == -1) {
        QMessageBox::critical(this, "发送失败", m_pSerialPort->errorString());
    } else {
        ui->sendArea->clear();
    }
}

// 串口错误处理
void SerialPort::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError ||
            error == QSerialPort::PermissionError ||
            error == QSerialPort::DeviceNotFoundError) {

        if (m_isOpen) {
            onOpenPort();  // 自动关闭串口并恢复UI
        }
    }
}

void SerialPort::setWidgetsEnabled(bool enabled)
{
    ui->comboBoxPort->setEnabled(enabled);
    ui->comboBoxBaudRate->setEnabled(enabled);
    ui->comboBoxDatabits->setEnabled(enabled);
    ui->comboBoxParity->setEnabled(enabled);
    ui->comboBoxStopbit->setEnabled(enabled);
    ui->comboBoxFlowctr->setEnabled(enabled);
}

void SerialPort::closeEvent(QCloseEvent *event)
{
    emit aboutToClose();    // 发送自定义信号
    if (m_pSerialPort->isOpen()) {
        m_pSerialPort->close();
    }
    event->accept();
}

SerialPort::~SerialPort()
{
    if(m_pSerialPort->isOpen()) {
        m_pSerialPort->close();
    }
    delete ui;
}
