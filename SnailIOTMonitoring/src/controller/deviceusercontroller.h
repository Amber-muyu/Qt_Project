#ifndef DEVICEUSERCONTROLLER_H
#define DEVICEUSERCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTimer>
#include "../database/devicemanager.h"

namespace Ui {
class DeviceUserController;
}

class DeviceUserController : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceUserController(QWidget *parent = nullptr);
    ~DeviceUserController();
    void initDeviceInfoPage(const QList<QVariantMap>& Devices);
    void autoRefresh();

signals:
    void sendModifyDeviceInfo(int);

private:
    Ui::DeviceUserController *ui;
    QStandardItemModel* m_model = nullptr;
    bool m_isSearching;
};

#endif // DEVICEUSERCONTROLLER_H
