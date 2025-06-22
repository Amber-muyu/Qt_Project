#include "realtimechart.h"
#include "ui_realtimechart.h"

#include <QDateTime>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QHBoxLayout>

RealTimeChart::RealTimeChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimeChart)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(0, "折线图");
    ui->tabWidget->setTabText(1, "柱状图");

    // 定义需要显示的字段 (可按需增减)
    m_fields = {
        {"temperature", "温度(°C)",   Qt::red},
        {"humidity",    "湿度(%)",    Qt::blue},
        {"light",       "光照(lux)", Qt::magenta},
        {"co2",         "CO₂(ppm)",  Qt::darkGreen},
        {"pressure",    "气压(hPa)", Qt::darkCyan}
    };

    initCharts();
}

void RealTimeChart::initCharts()
{
    // UI 里已经有 tabWidget (objectName: tabWidget)
    initLineChart();
    initBarChart();

    // 将 ChartView 填入两页
    if (auto *layout1 = new QHBoxLayout(ui->lineTab)) {
        layout1->setContentsMargins(0,0,0,0);
        layout1->addWidget(m_lineView);
    }
    if (auto *layout2 = new QHBoxLayout(ui->barTab)) {
        layout2->setContentsMargins(0,0,0,0);
        layout2->addWidget(m_barView);
    }
}

void RealTimeChart::initLineChart()
{
    m_lineChart = new QChart();
    m_lineChart->legend()->setAlignment(Qt::AlignBottom);

    // X 轴：时间
    m_axisX = new QDateTimeAxis;
    m_axisX->setFormat("HH:mm:ss");
    m_axisX->setTitleText("时间");

    // Y 轴：数值
    m_axisY = new QValueAxis;
    m_axisY->setTitleText("数值");
    m_axisY->setRange(0, 100);

    m_lineChart->addAxis(m_axisX, Qt::AlignBottom);
    m_lineChart->addAxis(m_axisY, Qt::AlignLeft);

    // 创建曲线
    for (const auto &f : m_fields) {
        QLineSeries *s = new QLineSeries;
        s->setName(f.name);
        s->setColor(f.color);
        m_series.insert(f.key, s);
        m_lineChart->addSeries(s);
        s->attachAxis(m_axisX);
        s->attachAxis(m_axisY);
    }

    m_lineView = new QChartView(m_lineChart);
    m_lineView->setRenderHint(QPainter::Antialiasing);
}

void RealTimeChart::initBarChart()
{
    m_barChart = new QChart();
    m_barSet  = new QBarSet("实时值");
    *m_barSet << 0 << 0 << 0 << 0 << 0;  // 初始值

    m_barSeries = new QBarSeries();
    m_barSeries->append(m_barSet);
    m_barChart->addSeries(m_barSeries);
    m_barChart->legend()->hide();

    // X 轴分类标签
    m_barAxisX = new QBarCategoryAxis;
    for (const auto &f : m_fields) m_barAxisX->append(f.name);
    m_barChart->addAxis(m_barAxisX, Qt::AlignBottom);
    m_barSeries->attachAxis(m_barAxisX);

    // Y 轴
    m_barAxisY = new QValueAxis;
    m_barAxisY->setRange(0, 100);
    m_barChart->addAxis(m_barAxisY, Qt::AlignLeft);
    m_barSeries->attachAxis(m_barAxisY);

    m_barView = new QChartView(m_barChart);
    m_barView->setRenderHint(QPainter::Antialiasing);
}

//接收串口 QVariantMap 数据 → 更新图表
void RealTimeChart::updateCharts(const QVariantMap &data)
{
    // 解析时间
    QDateTime ts;
    if (data.contains("timestamp")) {
        ts = QDateTime::fromString(data.value("timestamp").toString(), Qt::ISODate);
    }
    if (!ts.isValid()) ts = QDateTime::currentDateTime();

    qint64 x = ts.toMSecsSinceEpoch();
    ++m_index;  // 用于柱状图的标签

    // 更新柱状图 barSet
    m_barSet->remove(0, m_barSet->count());

    int barPos = 0;
    double maxY = m_axisY->max();

    for (const auto &f : m_fields) {
        double y = data.value(f.key).toDouble();
        // 折线图
        if (m_series.contains(f.key)) {
            appendLinePoint(f.key, x, y);
            if (y > maxY) maxY = y;
        }
        // 柱状填充
        m_barSet->append(y);
        ++barPos;
    }

    // 更新坐标轴范围
    m_axisX->setRange(ts.addSecs(-m_maxPoints), ts);
    m_axisY->setMax(maxY + 10);

    m_barAxisY->setMax(maxY + 10);

    // 更新柱状图 X 轴分类可选：不变
    m_barChart->update();
}

void RealTimeChart::appendLinePoint(const QString &key, qint64 x,qreal y)
{
    QLineSeries *s = m_series.value(key, nullptr);
    if (!s) return;

    s->append(x,y);
    if (s->count() > m_maxPoints)
        s->remove(0, s->count() - m_maxPoints);
}

RealTimeChart::~RealTimeChart()
{
    delete ui;
}
