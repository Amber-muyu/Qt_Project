/********************************************************************************
** Form generated from reading UI file 'admindeviceinfoadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDEVICEINFOADD_H
#define UI_ADMINDEVICEINFOADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminDeviceInfoAdd
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelAddType;
    QLineEdit *lineEditAddType;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_9;
    QLabel *labelAddModel;
    QLineEdit *lineEditAddModel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelAddManufacturer;
    QLineEdit *lineEditAddManufacturer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelAdd;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelAddName;
    QLineEdit *lineEditAddName;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddOK;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelAddLocation;
    QLineEdit *lineEditAddLocation;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *AdminDeviceInfoAdd)
    {
        if (AdminDeviceInfoAdd->objectName().isEmpty())
            AdminDeviceInfoAdd->setObjectName(QString::fromUtf8("AdminDeviceInfoAdd"));
        AdminDeviceInfoAdd->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminDeviceInfoAdd);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelAddType = new QLabel(AdminDeviceInfoAdd);
        labelAddType->setObjectName(QString::fromUtf8("labelAddType"));
        labelAddType->setMinimumSize(QSize(100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelAddType->setFont(font);
        labelAddType->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelAddType);

        lineEditAddType = new QLineEdit(AdminDeviceInfoAdd);
        lineEditAddType->setObjectName(QString::fromUtf8("lineEditAddType"));
        lineEditAddType->setMinimumSize(QSize(350, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditAddType->setFont(font1);

        horizontalLayout_2->addWidget(lineEditAddType);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        labelAddModel = new QLabel(AdminDeviceInfoAdd);
        labelAddModel->setObjectName(QString::fromUtf8("labelAddModel"));
        labelAddModel->setMinimumSize(QSize(100, 40));
        labelAddModel->setFont(font);
        labelAddModel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelAddModel);

        lineEditAddModel = new QLineEdit(AdminDeviceInfoAdd);
        lineEditAddModel->setObjectName(QString::fromUtf8("lineEditAddModel"));
        lineEditAddModel->setMinimumSize(QSize(350, 40));
        lineEditAddModel->setFont(font1);

        horizontalLayout_7->addWidget(lineEditAddModel);


        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        labelAddManufacturer = new QLabel(AdminDeviceInfoAdd);
        labelAddManufacturer->setObjectName(QString::fromUtf8("labelAddManufacturer"));
        labelAddManufacturer->setMinimumSize(QSize(100, 40));
        labelAddManufacturer->setFont(font);
        labelAddManufacturer->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelAddManufacturer);

        lineEditAddManufacturer = new QLineEdit(AdminDeviceInfoAdd);
        lineEditAddManufacturer->setObjectName(QString::fromUtf8("lineEditAddManufacturer"));
        lineEditAddManufacturer->setMinimumSize(QSize(350, 40));
        lineEditAddManufacturer->setFont(font1);

        horizontalLayout_4->addWidget(lineEditAddManufacturer);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelAdd = new QLabel(AdminDeviceInfoAdd);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setMinimumSize(QSize(200, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        labelAdd->setFont(font2);
        labelAdd->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelAdd);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelAddName = new QLabel(AdminDeviceInfoAdd);
        labelAddName->setObjectName(QString::fromUtf8("labelAddName"));
        labelAddName->setMinimumSize(QSize(100, 40));
        labelAddName->setFont(font);
        labelAddName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelAddName);

        lineEditAddName = new QLineEdit(AdminDeviceInfoAdd);
        lineEditAddName->setObjectName(QString::fromUtf8("lineEditAddName"));
        lineEditAddName->setMinimumSize(QSize(350, 40));
        lineEditAddName->setFont(font1);

        horizontalLayout->addWidget(lineEditAddName);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnAddOK = new QPushButton(AdminDeviceInfoAdd);
        btnAddOK->setObjectName(QString::fromUtf8("btnAddOK"));
        btnAddOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_6->addWidget(btnAddOK);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labelAddLocation = new QLabel(AdminDeviceInfoAdd);
        labelAddLocation->setObjectName(QString::fromUtf8("labelAddLocation"));
        labelAddLocation->setMinimumSize(QSize(100, 40));
        labelAddLocation->setFont(font);
        labelAddLocation->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelAddLocation);

        lineEditAddLocation = new QLineEdit(AdminDeviceInfoAdd);
        lineEditAddLocation->setObjectName(QString::fromUtf8("lineEditAddLocation"));
        lineEditAddLocation->setMinimumSize(QSize(350, 40));
        lineEditAddLocation->setFont(font1);

        horizontalLayout_3->addWidget(lineEditAddLocation);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(AdminDeviceInfoAdd);

        QMetaObject::connectSlotsByName(AdminDeviceInfoAdd);
    } // setupUi

    void retranslateUi(QWidget *AdminDeviceInfoAdd)
    {
        AdminDeviceInfoAdd->setWindowTitle(QCoreApplication::translate("AdminDeviceInfoAdd", "Form", nullptr));
        labelAddType->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", nullptr));
        labelAddModel->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\350\256\276\345\244\207\345\236\213\345\217\267\357\274\232", nullptr));
        labelAddManufacturer->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\345\210\266\351\200\240\345\225\206\357\274\232", nullptr));
        labelAdd->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\346\226\260\345\242\236\350\256\276\345\244\207", nullptr));
        labelAddName->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\350\256\276\345\244\207\345\220\215\357\274\232", nullptr));
        btnAddOK->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\347\241\256\350\256\244", nullptr));
        labelAddLocation->setText(QCoreApplication::translate("AdminDeviceInfoAdd", "\345\256\211\350\243\205\344\275\215\347\275\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDeviceInfoAdd: public Ui_AdminDeviceInfoAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDEVICEINFOADD_H
