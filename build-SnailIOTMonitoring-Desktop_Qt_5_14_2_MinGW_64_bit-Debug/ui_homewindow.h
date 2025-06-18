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
#include <QtWidgets/QLabel>
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
    QWidget *page;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QString::fromUtf8("HomeWindow"));
        HomeWindow->resize(800, 600);
        gridLayout = new QGridLayout(HomeWindow);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
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
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 258, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 257, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 1, 1, 1);

        stackedWidget->addWidget(page);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(HomeWindow);

        stackedWidget->setCurrentIndex(0);


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
        label->setText(QCoreApplication::translate("HomeWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\234\254\347\211\251\350\201\224\347\275\221\347\233\221\346\216\247\346\216\247\347\256\241\347\220\206\345\271\263\345\217\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
