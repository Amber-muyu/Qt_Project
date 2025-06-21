#ifndef DATAADMINCONTROLLER_H
#define DATAADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTimer>
#include <QDateTimeEdit>
#include <QFileDialog>
#include "../database/datamanager.h"
#include "../serial/serialport.h"
#include "../chart/realtimechart.h"

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
    void realShowData();
    void onSerialDataReceived(const QVariantMap &data);
private:
    Ui::DataAdminController *ui;
    SerialPort* m_serialPort = nullptr;
    RealTimeChart* m_realTimeChar = nullptr;
    QStandardItemModel* m_model = nullptr;
    bool m_isSearching;
};

#endif // DATAADMINCONTROLLER_H
