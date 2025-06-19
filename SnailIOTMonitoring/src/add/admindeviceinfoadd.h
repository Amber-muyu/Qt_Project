#ifndef ADMINDEVICEINFOADD_H
#define ADMINDEVICEINFOADD_H

#include <QWidget>
#include "../database/devicemanager.h"

namespace Ui {
class AdminDeviceInfoAdd;
}

class AdminDeviceInfoAdd : public QWidget
{
    Q_OBJECT

public:
    explicit AdminDeviceInfoAdd(QWidget *parent = nullptr);
    ~AdminDeviceInfoAdd();

public slots:
    void addDeviceInfo();

signals:
    void addFinish(const QString&);

private:
    Ui::AdminDeviceInfoAdd *ui;
};

#endif // ADMINDEVICEINFOADD_H
