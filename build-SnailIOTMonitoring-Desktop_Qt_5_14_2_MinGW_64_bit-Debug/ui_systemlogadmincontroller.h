/********************************************************************************
** Form generated from reading UI file 'systemlogadmincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMLOGADMINCONTROLLER_H
#define UI_SYSTEMLOGADMINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemLogAdminController
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnDeleteLog;
    QLabel *labelSearch;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditSelectLog;
    QPushButton *btnExportLog;
    QTableView *tableView;

    void setupUi(QWidget *SystemLogAdminController)
    {
        if (SystemLogAdminController->objectName().isEmpty())
            SystemLogAdminController->setObjectName(QString::fromUtf8("SystemLogAdminController"));
        SystemLogAdminController->resize(800, 600);
        gridLayout_2 = new QGridLayout(SystemLogAdminController);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelTitle = new QLabel(SystemLogAdminController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(SystemLogAdminController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        btnDeleteLog = new QPushButton(widget);
        btnDeleteLog->setObjectName(QString::fromUtf8("btnDeleteLog"));
        btnDeleteLog->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDeleteLog, 0, 3, 1, 1);

        labelSearch = new QLabel(widget);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        labelSearch->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelSearch->setFont(font1);
        labelSearch->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSearch, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        lineEditSelectLog = new QLineEdit(widget);
        lineEditSelectLog->setObjectName(QString::fromUtf8("lineEditSelectLog"));
        lineEditSelectLog->setMinimumSize(QSize(210, 30));
        lineEditSelectLog->setFont(font1);

        gridLayout->addWidget(lineEditSelectLog, 0, 1, 1, 1);

        btnExportLog = new QPushButton(widget);
        btnExportLog->setObjectName(QString::fromUtf8("btnExportLog"));
        btnExportLog->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnExportLog, 0, 4, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(SystemLogAdminController);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(SystemLogAdminController);

        QMetaObject::connectSlotsByName(SystemLogAdminController);
    } // setupUi

    void retranslateUi(QWidget *SystemLogAdminController)
    {
        SystemLogAdminController->setWindowTitle(QCoreApplication::translate("SystemLogAdminController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("SystemLogAdminController", "\347\263\273\347\273\237\346\227\245\345\277\227\347\256\241\347\220\206", nullptr));
        btnDeleteLog->setText(QCoreApplication::translate("SystemLogAdminController", "\345\210\240\351\231\244\346\227\245\345\277\227", nullptr));
        labelSearch->setText(QCoreApplication::translate("SystemLogAdminController", "\346\220\234\347\264\242", nullptr));
        btnExportLog->setText(QCoreApplication::translate("SystemLogAdminController", "\346\227\245\345\277\227\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemLogAdminController: public Ui_SystemLogAdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMLOGADMINCONTROLLER_H
