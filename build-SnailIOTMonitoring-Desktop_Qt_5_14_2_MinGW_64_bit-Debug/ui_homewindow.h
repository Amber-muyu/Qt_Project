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
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *btnDevice;
    QPushButton *btnAlarm;
    QPushButton *btnLog;
    QPushButton *btnLogout;
    QPushButton *btnData;
    QPushButton *btnSystem;
    QSpacerItem *verticalSpacer;
    QPushButton *btnUser;
    QPushButton *btnDataAnalysis;
    QStackedWidget *stackedWidget;
    QWidget *pageUser;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLabel *labelTextUserName;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelEmail;
    QLabel *labelTextEmail;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPhone;
    QLabel *labelTextPhone;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelRole;
    QLabel *labelTextRole;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnInfoModify;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnInfoModify_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QWidget *pageDevice;
    QWidget *pageData;
    QWidget *pageAlarm;
    QWidget *pageDataAnalysis;
    QWidget *pageSystem;
    QWidget *pageLog;

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
        btnDevice = new QPushButton(widget);
        btnDevice->setObjectName(QString::fromUtf8("btnDevice"));
        btnDevice->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnDevice, 1, 0, 1, 1);

        btnAlarm = new QPushButton(widget);
        btnAlarm->setObjectName(QString::fromUtf8("btnAlarm"));
        btnAlarm->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnAlarm, 3, 0, 1, 1);

        btnLog = new QPushButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        btnLog->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnLog, 6, 0, 1, 1);

        btnLogout = new QPushButton(widget);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));

        gridLayout_2->addWidget(btnLogout, 8, 0, 1, 1);

        btnData = new QPushButton(widget);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        btnData->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnData, 2, 0, 1, 1);

        btnSystem = new QPushButton(widget);
        btnSystem->setObjectName(QString::fromUtf8("btnSystem"));
        btnSystem->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnSystem, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 133, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);

        btnUser = new QPushButton(widget);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));
        btnUser->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnUser, 0, 0, 1, 1);

        btnDataAnalysis = new QPushButton(widget);
        btnDataAnalysis->setObjectName(QString::fromUtf8("btnDataAnalysis"));
        btnDataAnalysis->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnDataAnalysis, 4, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(HomeWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        pageUser = new QWidget();
        pageUser->setObjectName(QString::fromUtf8("pageUser"));
        gridLayout_5 = new QGridLayout(pageUser);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_6 = new QSpacerItem(20, 89, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(pageUser);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setMinimumSize(QSize(100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelUserName->setFont(font);
        labelUserName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelUserName);

        labelTextUserName = new QLabel(pageUser);
        labelTextUserName->setObjectName(QString::fromUtf8("labelTextUserName"));
        labelTextUserName->setMinimumSize(QSize(350, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelTextUserName->setFont(font1);
        labelTextUserName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(labelTextUserName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelEmail = new QLabel(pageUser);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setMinimumSize(QSize(100, 50));
        labelEmail->setFont(font);
        labelEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelEmail);

        labelTextEmail = new QLabel(pageUser);
        labelTextEmail->setObjectName(QString::fromUtf8("labelTextEmail"));
        labelTextEmail->setMinimumSize(QSize(350, 50));
        labelTextEmail->setFont(font1);
        labelTextEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(labelTextEmail);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPhone = new QLabel(pageUser);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setMinimumSize(QSize(100, 50));
        labelPhone->setFont(font);
        labelPhone->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelPhone);

        labelTextPhone = new QLabel(pageUser);
        labelTextPhone->setObjectName(QString::fromUtf8("labelTextPhone"));
        labelTextPhone->setMinimumSize(QSize(350, 50));
        labelTextPhone->setFont(font1);
        labelTextPhone->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(labelTextPhone);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRole = new QLabel(pageUser);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));
        labelRole->setMinimumSize(QSize(100, 50));
        labelRole->setFont(font);
        labelRole->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRole);

        labelTextRole = new QLabel(pageUser);
        labelTextRole->setObjectName(QString::fromUtf8("labelTextRole"));
        labelTextRole->setMinimumSize(QSize(350, 50));
        labelTextRole->setFont(font1);
        labelTextRole->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(labelTextRole);


        gridLayout_3->addLayout(horizontalLayout_4, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 7, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnInfoModify = new QPushButton(pageUser);
        btnInfoModify->setObjectName(QString::fromUtf8("btnInfoModify"));
        btnInfoModify->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModify);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnInfoModify_2 = new QPushButton(pageUser);
        btnInfoModify_2->setObjectName(QString::fromUtf8("btnInfoModify_2"));
        btnInfoModify_2->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModify_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(83, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_7, 2, 1, 1, 1);

        stackedWidget->addWidget(pageUser);
        pageDevice = new QWidget();
        pageDevice->setObjectName(QString::fromUtf8("pageDevice"));
        stackedWidget->addWidget(pageDevice);
        pageData = new QWidget();
        pageData->setObjectName(QString::fromUtf8("pageData"));
        stackedWidget->addWidget(pageData);
        pageAlarm = new QWidget();
        pageAlarm->setObjectName(QString::fromUtf8("pageAlarm"));
        stackedWidget->addWidget(pageAlarm);
        pageDataAnalysis = new QWidget();
        pageDataAnalysis->setObjectName(QString::fromUtf8("pageDataAnalysis"));
        stackedWidget->addWidget(pageDataAnalysis);
        pageSystem = new QWidget();
        pageSystem->setObjectName(QString::fromUtf8("pageSystem"));
        stackedWidget->addWidget(pageSystem);
        pageLog = new QWidget();
        pageLog->setObjectName(QString::fromUtf8("pageLog"));
        stackedWidget->addWidget(pageLog);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(HomeWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QWidget *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "Form", nullptr));
        btnDevice->setText(QCoreApplication::translate("HomeWindow", "\350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
        btnAlarm->setText(QCoreApplication::translate("HomeWindow", "\350\255\246\345\221\212\347\256\241\347\220\206", nullptr));
        btnLog->setText(QCoreApplication::translate("HomeWindow", "\346\227\245\345\277\227\347\256\241\347\220\206", nullptr));
        btnLogout->setText(QCoreApplication::translate("HomeWindow", "\347\231\273\345\207\272", nullptr));
        btnData->setText(QCoreApplication::translate("HomeWindow", "\346\225\260\346\215\256\347\233\221\346\216\247", nullptr));
        btnSystem->setText(QCoreApplication::translate("HomeWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnUser->setText(QCoreApplication::translate("HomeWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        btnDataAnalysis->setText(QCoreApplication::translate("HomeWindow", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        labelUserName->setText(QCoreApplication::translate("HomeWindow", "\347\224\250\346\210\267\357\274\232", nullptr));
        labelTextUserName->setText(QString());
        labelEmail->setText(QCoreApplication::translate("HomeWindow", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelTextEmail->setText(QString());
        labelPhone->setText(QCoreApplication::translate("HomeWindow", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelTextPhone->setText(QString());
        labelRole->setText(QCoreApplication::translate("HomeWindow", "\350\247\222\350\211\262\357\274\232", nullptr));
        labelTextRole->setText(QString());
        btnInfoModify->setText(QCoreApplication::translate("HomeWindow", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        btnInfoModify_2->setText(QCoreApplication::translate("HomeWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
