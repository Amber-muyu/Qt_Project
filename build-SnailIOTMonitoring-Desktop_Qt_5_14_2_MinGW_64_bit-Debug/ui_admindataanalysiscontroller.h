/********************************************************************************
** Form generated from reading UI file 'admindataanalysiscontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDATAANALYSISCONTROLLER_H
#define UI_ADMINDATAANALYSISCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminDataAnalysisController
{
public:
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxDevice;
    QComboBox *comboBoxItem;
    QDateTimeEdit *dateTimeEditFrom;
    QDateTimeEdit *dateTimeEditTo;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *AdminDataAnalysisController)
    {
        if (AdminDataAnalysisController->objectName().isEmpty())
            AdminDataAnalysisController->setObjectName(QString::fromUtf8("AdminDataAnalysisController"));
        AdminDataAnalysisController->resize(800, 600);
        gridLayout = new QGridLayout(AdminDataAnalysisController);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        labelTitle = new QLabel(AdminDataAnalysisController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(AdminDataAnalysisController);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxDevice = new QComboBox(widget);
        comboBoxDevice->setObjectName(QString::fromUtf8("comboBoxDevice"));
        comboBoxDevice->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(comboBoxDevice);

        comboBoxItem = new QComboBox(widget);
        comboBoxItem->setObjectName(QString::fromUtf8("comboBoxItem"));
        comboBoxItem->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(comboBoxItem);

        dateTimeEditFrom = new QDateTimeEdit(widget);
        dateTimeEditFrom->setObjectName(QString::fromUtf8("dateTimeEditFrom"));
        dateTimeEditFrom->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(dateTimeEditFrom);

        dateTimeEditTo = new QDateTimeEdit(widget);
        dateTimeEditTo->setObjectName(QString::fromUtf8("dateTimeEditTo"));
        dateTimeEditTo->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(dateTimeEditTo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(btnOK);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        tabWidget = new QTabWidget(AdminDataAnalysisController);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 5);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowStretch(2, 200);

        retranslateUi(AdminDataAnalysisController);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminDataAnalysisController);
    } // setupUi

    void retranslateUi(QWidget *AdminDataAnalysisController)
    {
        AdminDataAnalysisController->setWindowTitle(QCoreApplication::translate("AdminDataAnalysisController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("AdminDataAnalysisController", "\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226\345\210\206\346\236\220", nullptr));
        btnOK->setText(QCoreApplication::translate("AdminDataAnalysisController", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AdminDataAnalysisController", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AdminDataAnalysisController", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDataAnalysisController: public Ui_AdminDataAnalysisController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDATAANALYSISCONTROLLER_H
