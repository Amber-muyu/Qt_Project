#ifndef ADMINDEVICEINFOMODIFY_H
#define ADMINDEVICEINFOMODIFY_H

#include <QWidget>
#include "../database/devicemanager.h"
#include "../database/usermanager.h"
#include "../database/systemlogsmanager.h"

namespace Ui {
class AdminDeviceInfoModify;
}

class AdminDeviceInfoModify : public QWidget
{
    Q_OBJECT

public:
    explicit AdminDeviceInfoModify(QWidget *parent = nullptr);
    ~AdminDeviceInfoModify();

public slots:
    void modifyByDeviceId(int);
    void modifyDeviceInfo();

signals:
    void modifyFinish(const QString&);

private:
    Ui::AdminDeviceInfoModify *ui;
    int m_deviceId = -1;
};

#endif // ADMINDEVICEINFOMODIFY_H
