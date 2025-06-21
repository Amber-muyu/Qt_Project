#ifndef REALTIMECHART_H
#define REALTIMECHART_H

#include <QWidget>
#include <QScopedPointer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QVariantMap>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class RealTimeChart;
}

struct SensorField {
    QString key;
    QString name;
    QColor  color;
};

class RealTimeChart : public QWidget
{
    Q_OBJECT

public:
    explicit RealTimeChart(QWidget *parent = nullptr);
    ~RealTimeChart();

public slots:
    void updateCharts(const QVariantMap &data);

private:
    // 初始化所有图表控件
    void initCharts();
    void initLineChart();
    void initBarChart();

    // 更新折线图与柱状图内部方法
    void appendLinePoint(const QString &key, qint64 x, qreal y);
    void refreshBarChart(const QVariantMap &data);

private:
    Ui::RealTimeChart *ui;

    // 折线图成员
    QChart        *m_lineChart  { nullptr };
    QChartView    *m_lineView   { nullptr };
    QDateTimeAxis *m_axisX      { nullptr };
    QValueAxis    *m_axisY      { nullptr };
    QHash<QString, QLineSeries*> m_series;   // key -> series

    // 柱状图成员
    QChart        *m_barChart   { nullptr };
    QChartView    *m_barView    { nullptr };
    QBarSeries    *m_barSeries  { nullptr };
    QBarSet       *m_barSet     { nullptr };
    QBarCategoryAxis *m_barAxisX{ nullptr };
    QValueAxis    *m_barAxisY   { nullptr };

    // 其他
    QList<SensorField> m_fields;
    qint64 m_index = 0;                  // 折线图 X 轴点序
    const int m_maxPoints = 120;         // 滑动窗口大小
};

#endif // REALTIMECHART_H
