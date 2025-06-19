#ifndef DEVICEADMINCONTROLLER_H
#define DEVICEADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTime>
#include "../database/devicemanager.h"
#include "../add/admindeviceinfoadd.h"
#include "../modify/admindeviceinfomodify.h"

namespace Ui {
class DeviceAdminController;
}

class DeviceAdminController : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceAdminController(QWidget *parent = nullptr);
    ~DeviceAdminController();
    void initDeviceInfoPage(const QList<QVariantMap>& Devices);
    void autoRefresh();

public slots:
    void addDevice();
    void modifyDevice();
    void deleteDevice();

signals:
    void sendModifyDeviceInfo(int);

private:
    Ui::DeviceAdminController *ui;
    QStandardItemModel* m_model = nullptr;
    AdminDeviceInfoAdd* m_adminDeviceInfoAdd;
    AdminDeviceInfoModify* m_adminDeviceInfoModify;
    bool m_isSearching;
};

#endif // DEVICEADMINCONTROLLER_H
