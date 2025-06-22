#include "admindataanalysiscontroller.h"
#include "ui_admindataanalysiscontroller.h"

#include <QtCharts>
#include <QDebug>

AdminDataAnalysisController::AdminDataAnalysisController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminDataAnalysisController),
    chart(new QChart),
    chartView(new QChartView(chart)),
    series(new QLineSeries),
    axisX(new QDateTimeAxis),
    axisY(new QValueAxis)
{
    ui->setupUi(this);

    ui->dateTimeEditFrom->setDate(QDate::currentDate());
    ui->dateTimeEditFrom->setCalendarPopup(true);
    ui->dateTimeEditTo->setDate(QDate::currentDate());
    ui->dateTimeEditTo->setCalendarPopup(true);

    ui->tabWidget->setTabText(0, "折线图");
    ui->tabWidget->setTabText(1, "数据统计");

    setupUiComponents();
    loadDeviceList();
    loadFieldList();
}

void AdminDataAnalysisController::setupUiComponents()
{
    axisX->setFormat("yyyy-MM-dd HH:mm:ss");
    axisX->setTitleText("时间");
    axisY->setTitleText("数值");

    chart->addSeries(series);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chart->setTitle("数据趋势图");

    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);
}

void AdminDataAnalysisController::loadDeviceList()
{
    ui->comboBoxDevice->addItem("设备1", 1);
    ui->comboBoxDevice->addItem("设备2", 2);
    ui->comboBoxDevice->addItem("设备3", 3);
    ui->comboBoxDevice->addItem("设备4", 4);
    ui->comboBoxDevice->addItem("设备5", 5);
}

void AdminDataAnalysisController::loadFieldList()
{
    ui->comboBoxItem->addItem("温度", "temperature");
    ui->comboBoxItem->addItem("湿度", "humidity");
    ui->comboBoxItem->addItem("CO2", "co2");
    ui->comboBoxItem->addItem("光照", "light");
    ui->comboBoxItem->addItem("气压", "pressure");
}

QList<QVariantMap> AdminDataAnalysisController::fetchData(int deviceId, const QString &field, const QDateTime &from, const QDateTime &to)
{
    QList<QVariantMap> result;
    QSqlQuery query;
    query.prepare("SELECT timestamp, " + field + " FROM data WHERE device_id = :id AND timestamp BETWEEN :from AND :to ORDER BY timestamp");
    query.bindValue(":id", deviceId);
    query.bindValue(":from", from);
    query.bindValue(":to", to);

    if (query.exec()) {
        while (query.next()) {
            QVariantMap row;
            row["timestamp"] = query.value(0);
            row[field] = query.value(1);
            result.append(row);
        }
    }
    return result;
}

void AdminDataAnalysisController::drawLineChart(const QList<QVariantMap> &data, const QString &field)
{
    series->clear();

    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();

    for (const auto &row : data) {
        QDateTime dt = QDateTime::fromString(row["timestamp"].toString(), Qt::ISODate);
        if (!dt.isValid()) continue;

        double y = row[field].toDouble();
        series->append(dt.toMSecsSinceEpoch(), y);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }
    if (!data.isEmpty()) {
        axisX->setRange(
                QDateTime::fromString(data.first()["timestamp"].toString(), Qt::ISODate),
                QDateTime::fromString(data.last()["timestamp"].toString(), Qt::ISODate)
                );
        axisY->setRange(minY - 5, maxY + 5);

        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }
}

void AdminDataAnalysisController::showStatistics(const QList<QVariantMap> &data, const QString &field)
{
    if (data.isEmpty()) return;

    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::lowest();
    double sum = 0;

    for (const auto &row : data) {
        double val = row[field].toDouble();
        min = std::min(min, val);
        max = std::max(max, val);
        sum += val;
    }
    double avg = sum / data.size();

    QString stats = QString("平均值: %1\n最大值: %2\n最小值: %3")
            .arg(avg, 0, 'f', 2)
            .arg(max, 0, 'f', 2)
            .arg(min, 0, 'f', 2);

    QTextEdit *textEdit = ui->tabWidget->widget(1)->findChild<QTextEdit *>();
    if (textEdit) textEdit->setPlainText(stats);
}

void AdminDataAnalysisController::on_btnOK_clicked()
{
    int deviceId = ui->comboBoxDevice->currentData().toInt();
    QString field = ui->comboBoxItem->currentData().toString();
    QDateTime from = ui->dateTimeEditFrom->dateTime();
    QDateTime to = ui->dateTimeEditTo->dateTime();

    QList<QVariantMap> data = fetchData(deviceId, field, from, to);

    drawLineChart(data, field);
    showStatistics(data, field);
}


AdminDataAnalysisController::~AdminDataAnalysisController()
{
    delete ui;
}
