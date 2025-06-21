/********************************************************************************
** Form generated from reading UI file 'realtimelinechart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMELINECHART_H
#define UI_REALTIMELINECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeLineChart
{
public:

    void setupUi(QWidget *RealTimeLineChart)
    {
        if (RealTimeLineChart->objectName().isEmpty())
            RealTimeLineChart->setObjectName(QString::fromUtf8("RealTimeLineChart"));
        RealTimeLineChart->resize(400, 300);

        retranslateUi(RealTimeLineChart);

        QMetaObject::connectSlotsByName(RealTimeLineChart);
    } // setupUi

    void retranslateUi(QWidget *RealTimeLineChart)
    {
        RealTimeLineChart->setWindowTitle(QCoreApplication::translate("RealTimeLineChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RealTimeChart: public Ui_RealTimeLineChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMELINECHART_H
