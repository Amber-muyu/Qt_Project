#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QStringList>
#include <QCloseEvent>
#include "../database/datamanager.h"

namespace Ui {
class SerialPort;
}

class SerialPort : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPort(QWidget *parent = nullptr);
    ~SerialPort();
    void serialPortConfig();    //配置串口相关参数
    void setWidgetsEnabled(bool enabled);

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void onOpenPort();  //打开串口
    void readData();    //接受数据的槽函数
    void sendData();
    void handleError(QSerialPort::SerialPortError error);

signals:
    void aboutToClose();
    void addFinish(const QString&);
    void dataReceived(const QVariantMap &data);

private:
    Ui::SerialPort *ui;
    bool m_isOpen;
    QSerialPort* m_pSerialPort;
};

#endif // SERIALPORT_H
