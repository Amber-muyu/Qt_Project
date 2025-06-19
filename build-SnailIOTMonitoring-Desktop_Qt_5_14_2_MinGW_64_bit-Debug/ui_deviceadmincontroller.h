/********************************************************************************
** Form generated from reading UI file 'deviceadmincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEADMINCONTROLLER_H
#define UI_DEVICEADMINCONTROLLER_H

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

class Ui_DeviceAdminController
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDeleteDevice;
    QPushButton *btnModifyDevice;
    QLabel *labelSearch;
    QPushButton *btnAddDevice;
    QLineEdit *lineEditSelectDevice;
    QPushButton *btnGroupDevice;
    QTableView *tableView;

    void setupUi(QWidget *DeviceAdminController)
    {
        if (DeviceAdminController->objectName().isEmpty())
            DeviceAdminController->setObjectName(QString::fromUtf8("DeviceAdminController"));
        DeviceAdminController->resize(800, 600);
        gridLayout_2 = new QGridLayout(DeviceAdminController);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        labelTitle = new QLabel(DeviceAdminController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(DeviceAdminController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        btnDeleteDevice = new QPushButton(widget);
        btnDeleteDevice->setObjectName(QString::fromUtf8("btnDeleteDevice"));
        btnDeleteDevice->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDeleteDevice, 0, 5, 1, 1);

        btnModifyDevice = new QPushButton(widget);
        btnModifyDevice->setObjectName(QString::fromUtf8("btnModifyDevice"));
        btnModifyDevice->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnModifyDevice, 0, 4, 1, 1);

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

        btnAddDevice = new QPushButton(widget);
        btnAddDevice->setObjectName(QString::fromUtf8("btnAddDevice"));
        btnAddDevice->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnAddDevice, 0, 3, 1, 1);

        lineEditSelectDevice = new QLineEdit(widget);
        lineEditSelectDevice->setObjectName(QString::fromUtf8("lineEditSelectDevice"));
        lineEditSelectDevice->setMinimumSize(QSize(210, 30));
        lineEditSelectDevice->setFont(font1);

        gridLayout->addWidget(lineEditSelectDevice, 0, 1, 1, 1);

        btnGroupDevice = new QPushButton(widget);
        btnGroupDevice->setObjectName(QString::fromUtf8("btnGroupDevice"));
        btnGroupDevice->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnGroupDevice, 0, 6, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(DeviceAdminController);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(DeviceAdminController);

        QMetaObject::connectSlotsByName(DeviceAdminController);
    } // setupUi

    void retranslateUi(QWidget *DeviceAdminController)
    {
        DeviceAdminController->setWindowTitle(QCoreApplication::translate("DeviceAdminController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("DeviceAdminController", "\350\256\276\345\244\207\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        btnDeleteDevice->setText(QCoreApplication::translate("DeviceAdminController", "\345\210\240\351\231\244\350\256\276\345\244\207", nullptr));
        btnModifyDevice->setText(QCoreApplication::translate("DeviceAdminController", "\344\277\256\346\224\271\350\256\276\345\244\207", nullptr));
        labelSearch->setText(QCoreApplication::translate("DeviceAdminController", "\346\220\234\347\264\242", nullptr));
        btnAddDevice->setText(QCoreApplication::translate("DeviceAdminController", "\346\226\260\345\242\236\350\256\276\345\244\207", nullptr));
        btnGroupDevice->setText(QCoreApplication::translate("DeviceAdminController", "\350\256\276\345\244\207\345\210\206\347\273\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceAdminController: public Ui_DeviceAdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEADMINCONTROLLER_H
