/********************************************************************************
** Form generated from reading UI file 'dataadmincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAADMINCONTROLLER_H
#define UI_DATAADMINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataAdminController
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnAddData;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDeleteData;
    QPushButton *btnLineChart;
    QPushButton *btnBarChart;
    QPushButton *btnDataExport;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QDateTimeEdit *dateTimeEditTo;
    QDateTimeEdit *dateTimeEditFrom;
    QPushButton *btnSearch;
    QPushButton *btnReset;
    QTableView *tableView;

    void setupUi(QWidget *DataAdminController)
    {
        if (DataAdminController->objectName().isEmpty())
            DataAdminController->setObjectName(QString::fromUtf8("DataAdminController"));
        DataAdminController->resize(800, 600);
        gridLayout_2 = new QGridLayout(DataAdminController);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelTitle = new QLabel(DataAdminController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(DataAdminController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        btnAddData = new QPushButton(widget);
        btnAddData->setObjectName(QString::fromUtf8("btnAddData"));
        btnAddData->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnAddData, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        btnDeleteData = new QPushButton(widget);
        btnDeleteData->setObjectName(QString::fromUtf8("btnDeleteData"));
        btnDeleteData->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDeleteData, 0, 3, 1, 1);

        btnLineChart = new QPushButton(widget);
        btnLineChart->setObjectName(QString::fromUtf8("btnLineChart"));
        btnLineChart->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnLineChart, 0, 1, 1, 1);

        btnBarChart = new QPushButton(widget);
        btnBarChart->setObjectName(QString::fromUtf8("btnBarChart"));
        btnBarChart->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnBarChart, 0, 2, 1, 1);

        btnDataExport = new QPushButton(widget);
        btnDataExport->setObjectName(QString::fromUtf8("btnDataExport"));
        btnDataExport->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDataExport, 0, 4, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(DataAdminController);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(243, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        dateTimeEditTo = new QDateTimeEdit(widget_2);
        dateTimeEditTo->setObjectName(QString::fromUtf8("dateTimeEditTo"));
        dateTimeEditTo->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(dateTimeEditTo, 0, 2, 1, 1);

        dateTimeEditFrom = new QDateTimeEdit(widget_2);
        dateTimeEditFrom->setObjectName(QString::fromUtf8("dateTimeEditFrom"));
        dateTimeEditFrom->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(dateTimeEditFrom, 0, 1, 1, 1);

        btnSearch = new QPushButton(widget_2);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(btnSearch, 0, 3, 1, 1);

        btnReset = new QPushButton(widget_2);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setMinimumSize(QSize(0, 30));

        gridLayout_3->addWidget(btnReset, 0, 4, 1, 1);


        gridLayout_2->addWidget(widget_2, 2, 0, 1, 1);

        tableView = new QTableView(DataAdminController);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 3, 0, 1, 1);


        retranslateUi(DataAdminController);

        QMetaObject::connectSlotsByName(DataAdminController);
    } // setupUi

    void retranslateUi(QWidget *DataAdminController)
    {
        DataAdminController->setWindowTitle(QCoreApplication::translate("DataAdminController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("DataAdminController", "\346\225\260\346\215\256\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        btnAddData->setText(QCoreApplication::translate("DataAdminController", "\344\270\262\345\217\243\345\267\245\345\205\267", nullptr));
        btnDeleteData->setText(QCoreApplication::translate("DataAdminController", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        btnLineChart->setText(QCoreApplication::translate("DataAdminController", "\346\212\230\347\272\277\345\233\276", nullptr));
        btnBarChart->setText(QCoreApplication::translate("DataAdminController", "\346\237\261\347\212\266\345\233\276", nullptr));
        btnDataExport->setText(QCoreApplication::translate("DataAdminController", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        btnSearch->setText(QCoreApplication::translate("DataAdminController", "\346\220\234\347\264\242", nullptr));
        btnReset->setText(QCoreApplication::translate("DataAdminController", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataAdminController: public Ui_DataAdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAADMINCONTROLLER_H
