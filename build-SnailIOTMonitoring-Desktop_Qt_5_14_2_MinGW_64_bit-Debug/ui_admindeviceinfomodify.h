/********************************************************************************
** Form generated from reading UI file 'admindeviceinfomodify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDEVICEINFOMODIFY_H
#define UI_ADMINDEVICEINFOMODIFY_H

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

class Ui_AdminDeviceInfoModify
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelDeviceName;
    QLineEdit *lineEditModifyDeviceName;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelManufacturer;
    QLineEdit *lineEditModifyManufacturer;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *labelModel;
    QLineEdit *lineEditModifyModel;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelDeviceType;
    QLineEdit *lineEditModifyType;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelLocation;
    QLineEdit *lineEditModifyLocation;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_10;
    QLabel *labelStatus;
    QLineEdit *lineEditModifyStatus;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnInfoModifyOK;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *AdminDeviceInfoModify)
    {
        if (AdminDeviceInfoModify->objectName().isEmpty())
            AdminDeviceInfoModify->setObjectName(QString::fromUtf8("AdminDeviceInfoModify"));
        AdminDeviceInfoModify->resize(800, 600);
        layoutWidget = new QWidget(AdminDeviceInfoModify);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 50, 581, 506));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(220, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelDeviceName = new QLabel(layoutWidget);
        labelDeviceName->setObjectName(QString::fromUtf8("labelDeviceName"));
        labelDeviceName->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labelDeviceName->setFont(font1);
        labelDeviceName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelDeviceName);

        lineEditModifyDeviceName = new QLineEdit(layoutWidget);
        lineEditModifyDeviceName->setObjectName(QString::fromUtf8("lineEditModifyDeviceName"));
        lineEditModifyDeviceName->setMinimumSize(QSize(350, 50));

        horizontalLayout->addWidget(lineEditModifyDeviceName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        labelManufacturer = new QLabel(layoutWidget);
        labelManufacturer->setObjectName(QString::fromUtf8("labelManufacturer"));
        labelManufacturer->setMinimumSize(QSize(100, 50));
        labelManufacturer->setFont(font1);
        labelManufacturer->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelManufacturer);

        lineEditModifyManufacturer = new QLineEdit(layoutWidget);
        lineEditModifyManufacturer->setObjectName(QString::fromUtf8("lineEditModifyManufacturer"));
        lineEditModifyManufacturer->setMinimumSize(QSize(350, 50));

        horizontalLayout_3->addWidget(lineEditModifyManufacturer);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        labelModel = new QLabel(layoutWidget);
        labelModel->setObjectName(QString::fromUtf8("labelModel"));
        labelModel->setMinimumSize(QSize(100, 50));
        labelModel->setFont(font1);
        labelModel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelModel);

        lineEditModifyModel = new QLineEdit(layoutWidget);
        lineEditModifyModel->setObjectName(QString::fromUtf8("lineEditModifyModel"));
        lineEditModifyModel->setMinimumSize(QSize(350, 50));

        horizontalLayout_4->addWidget(lineEditModifyModel);


        gridLayout_3->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        labelDeviceType = new QLabel(layoutWidget);
        labelDeviceType->setObjectName(QString::fromUtf8("labelDeviceType"));
        labelDeviceType->setMinimumSize(QSize(100, 50));
        labelDeviceType->setFont(font1);
        labelDeviceType->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelDeviceType);

        lineEditModifyType = new QLineEdit(layoutWidget);
        lineEditModifyType->setObjectName(QString::fromUtf8("lineEditModifyType"));
        lineEditModifyType->setMinimumSize(QSize(350, 50));

        horizontalLayout_7->addWidget(lineEditModifyType);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        labelLocation = new QLabel(layoutWidget);
        labelLocation->setObjectName(QString::fromUtf8("labelLocation"));
        labelLocation->setMinimumSize(QSize(100, 50));
        labelLocation->setFont(font1);
        labelLocation->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelLocation);

        lineEditModifyLocation = new QLineEdit(layoutWidget);
        lineEditModifyLocation->setObjectName(QString::fromUtf8("lineEditModifyLocation"));
        lineEditModifyLocation->setMinimumSize(QSize(350, 50));

        horizontalLayout_2->addWidget(lineEditModifyLocation);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        labelStatus = new QLabel(layoutWidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setMinimumSize(QSize(100, 50));
        labelStatus->setFont(font1);
        labelStatus->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(labelStatus);

        lineEditModifyStatus = new QLineEdit(layoutWidget);
        lineEditModifyStatus->setObjectName(QString::fromUtf8("lineEditModifyStatus"));
        lineEditModifyStatus->setMinimumSize(QSize(350, 50));

        horizontalLayout_8->addWidget(lineEditModifyStatus);


        gridLayout_3->addLayout(horizontalLayout_8, 5, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnInfoModifyOK = new QPushButton(layoutWidget);
        btnInfoModifyOK->setObjectName(QString::fromUtf8("btnInfoModifyOK"));
        btnInfoModifyOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModifyOK);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 2, 0, 1, 1);


        retranslateUi(AdminDeviceInfoModify);

        QMetaObject::connectSlotsByName(AdminDeviceInfoModify);
    } // setupUi

    void retranslateUi(QWidget *AdminDeviceInfoModify)
    {
        AdminDeviceInfoModify->setWindowTitle(QCoreApplication::translate("AdminDeviceInfoModify", "Form", nullptr));
        label->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\350\256\276\345\244\207\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        labelDeviceName->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\350\256\276\345\244\207\345\220\215\357\274\232", nullptr));
        labelManufacturer->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\345\210\266\351\200\240\345\225\206\357\274\232", nullptr));
        labelModel->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\350\256\276\345\244\207\345\236\213\345\217\267\357\274\232", nullptr));
        labelDeviceType->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\347\261\273\345\236\213\357\274\232", nullptr));
        labelLocation->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\345\256\211\350\243\205\344\275\215\347\275\256\357\274\232", nullptr));
        labelStatus->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\347\212\266\346\200\201\357\274\232", nullptr));
        btnInfoModifyOK->setText(QCoreApplication::translate("AdminDeviceInfoModify", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDeviceInfoModify: public Ui_AdminDeviceInfoModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDEVICEINFOMODIFY_H
