/********************************************************************************
** Form generated from reading UI file 'deviceusercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEUSERCONTROLLER_H
#define UI_DEVICEUSERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceUserController
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSelectDevice;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *DeviceUserController)
    {
        if (DeviceUserController->objectName().isEmpty())
            DeviceUserController->setObjectName(QString::fromUtf8("DeviceUserController"));
        DeviceUserController->resize(800, 600);
        gridLayout_2 = new QGridLayout(DeviceUserController);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        labelTitle = new QLabel(DeviceUserController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(DeviceUserController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
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

        lineEditSelectDevice = new QLineEdit(widget);
        lineEditSelectDevice->setObjectName(QString::fromUtf8("lineEditSelectDevice"));
        lineEditSelectDevice->setMinimumSize(QSize(210, 30));
        lineEditSelectDevice->setFont(font1);

        gridLayout->addWidget(lineEditSelectDevice, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        tableView = new QTableView(DeviceUserController);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 1);


        retranslateUi(DeviceUserController);

        QMetaObject::connectSlotsByName(DeviceUserController);
    } // setupUi

    void retranslateUi(QWidget *DeviceUserController)
    {
        DeviceUserController->setWindowTitle(QCoreApplication::translate("DeviceUserController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("DeviceUserController", "\350\256\276\345\244\207\344\277\241\346\201\257\346\230\276\347\244\272", nullptr));
        labelSearch->setText(QCoreApplication::translate("DeviceUserController", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceUserController: public Ui_DeviceUserController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEUSERCONTROLLER_H
