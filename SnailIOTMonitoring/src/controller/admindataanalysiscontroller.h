#ifndef ADMINDATAANALYSISCONTROLLER_H
#define ADMINDATAANALYSISCONTROLLER_H

#include <QWidget>
#include <QMap>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class AdminDataAnalysisController;
}
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class AdminDataAnalysisController : public QWidget
{
    Q_OBJECT

public:
    explicit AdminDataAnalysisController(QWidget *parent = nullptr);
    ~AdminDataAnalysisController();

private slots:
    void on_btnOK_clicked();

private:
    void setupUiComponents();
    void loadDeviceList();
    void loadFieldList();
    void drawLineChart(const QList<QVariantMap> &data, const QString &field);
    void showStatistics(const QList<QVariantMap> &data, const QString &field);
    QList<QVariantMap> fetchData(int deviceId, const QString &field, const QDateTime &from, const QDateTime &to);

private:
    Ui::AdminDataAnalysisController *ui;
    QChart *chart;
    QChartView *chartView;
    QLineSeries *series;
    QDateTimeAxis *axisX;
    QValueAxis *axisY;
    QTableWidget *statsTable;
};

#endif // ADMINDATAANALYSISCONTROLLER_H
