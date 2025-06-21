/********************************************************************************
** Form generated from reading UI file 'realtimechart.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMECHART_H
#define UI_REALTIMECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeChart
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *lineTab;
    QWidget *barTab;

    void setupUi(QWidget *RealTimeChart)
    {
        if (RealTimeChart->objectName().isEmpty())
            RealTimeChart->setObjectName(QString::fromUtf8("RealTimeChart"));
        RealTimeChart->resize(800, 600);
        gridLayout = new QGridLayout(RealTimeChart);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(RealTimeChart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(RealTimeChart);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        lineTab = new QWidget();
        lineTab->setObjectName(QString::fromUtf8("lineTab"));
        tabWidget->addTab(lineTab, QString());
        barTab = new QWidget();
        barTab->setObjectName(QString::fromUtf8("barTab"));
        tabWidget->addTab(barTab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(RealTimeChart);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RealTimeChart);
    } // setupUi

    void retranslateUi(QWidget *RealTimeChart)
    {
        RealTimeChart->setWindowTitle(QCoreApplication::translate("RealTimeChart", "Form", nullptr));
        label->setText(QCoreApplication::translate("RealTimeChart", "\345\256\236\346\227\266\346\225\260\346\215\256\350\266\213\345\212\277\345\233\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(lineTab), QCoreApplication::translate("RealTimeChart", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(barTab), QCoreApplication::translate("RealTimeChart", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RealTimeChart: public Ui_RealTimeChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMECHART_H
