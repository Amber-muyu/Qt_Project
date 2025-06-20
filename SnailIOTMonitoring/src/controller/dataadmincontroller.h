#ifndef DATAADMINCONTROLLER_H
#define DATAADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTime>
#include <QDateTimeEdit>
#include <QFileDialog>
#include "../database/datamanager.h"
#include "../serial/serialport.h"

namespace Ui {
class DataAdminController;
}

class DataAdminController : public QWidget
{
    Q_OBJECT

public:
    explicit DataAdminController(QWidget *parent = nullptr);
    ~DataAdminController();
    void initDataInfoPage(const QList<QVariantMap>& Devices);
    void autoRefresh();
    void closeSerialPort();

public slots:
    void addData();
    void deleteData();
    void searchData();
    void resetData();
    void exportData();
private:
    Ui::DataAdminController *ui;
    SerialPort* m_serialPort = nullptr;
    QStandardItemModel* m_model = nullptr;
    bool m_isSearching;
};

#endif // DATAADMINCONTROLLER_H
