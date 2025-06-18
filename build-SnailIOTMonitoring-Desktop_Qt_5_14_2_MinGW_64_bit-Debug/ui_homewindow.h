/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btnSystem;
    QPushButton *btnUser;
    QPushButton *btnData;
    QPushButton *btnLog;
    QPushButton *btnAlarm;
    QPushButton *btnLogout;
    QPushButton *btnDataAnalysis;
    QSpacerItem *verticalSpacer;
    QPushButton *btnDevice;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QString::fromUtf8("HomeWindow"));
        HomeWindow->resize(800, 600);
        gridLayout = new QGridLayout(HomeWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(HomeWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 580));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnSystem = new QPushButton(widget);
        btnSystem->setObjectName(QString::fromUtf8("btnSystem"));
        btnSystem->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnSystem, 5, 0, 1, 1);

        btnUser = new QPushButton(widget);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));
        btnUser->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnUser, 0, 0, 1, 1);

        btnData = new QPushButton(widget);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        btnData->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnData, 2, 0, 1, 1);

        btnLog = new QPushButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        btnLog->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnLog, 6, 0, 1, 1);

        btnAlarm = new QPushButton(widget);
        btnAlarm->setObjectName(QString::fromUtf8("btnAlarm"));
        btnAlarm->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnAlarm, 3, 0, 1, 1);

        btnLogout = new QPushButton(widget);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));

        gridLayout_2->addWidget(btnLogout, 8, 0, 1, 1);

        btnDataAnalysis = new QPushButton(widget);
        btnDataAnalysis->setObjectName(QString::fromUtf8("btnDataAnalysis"));
        btnDataAnalysis->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnDataAnalysis, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 133, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);

        btnDevice = new QPushButton(widget);
        btnDevice->setObjectName(QString::fromUtf8("btnDevice"));
        btnDevice->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnDevice, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(HomeWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(HomeWindow);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QWidget *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "Form", nullptr));
        btnSystem->setText(QCoreApplication::translate("HomeWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnUser->setText(QCoreApplication::translate("HomeWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        btnData->setText(QCoreApplication::translate("HomeWindow", "\346\225\260\346\215\256\347\233\221\346\216\247", nullptr));
        btnLog->setText(QCoreApplication::translate("HomeWindow", "\346\227\245\345\277\227\347\256\241\347\220\206", nullptr));
        btnAlarm->setText(QCoreApplication::translate("HomeWindow", "\350\255\246\345\221\212\347\256\241\347\220\206", nullptr));
        btnLogout->setText(QCoreApplication::translate("HomeWindow", "\347\231\273\345\207\272", nullptr));
        btnDataAnalysis->setText(QCoreApplication::translate("HomeWindow", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        btnDevice->setText(QCoreApplication::translate("HomeWindow", "\350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
