/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelRegister;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelRegisterName;
    QLineEdit *lineEditRegisterName;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelRegisterPasswd;
    QLineEdit *lineEditRegisterPasswd;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelRegisterEmail;
    QLineEdit *lineEditRegisterEmail;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelRegisterTelephone;
    QLineEdit *lineEditRegisterTelephone;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnRegisterOK;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(800, 600);
        gridLayout_2 = new QGridLayout(RegisterWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelRegister = new QLabel(RegisterWindow);
        labelRegister->setObjectName(QString::fromUtf8("labelRegister"));
        labelRegister->setMinimumSize(QSize(200, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelRegister->setFont(font);
        labelRegister->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelRegister);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelRegisterName = new QLabel(RegisterWindow);
        labelRegisterName->setObjectName(QString::fromUtf8("labelRegisterName"));
        labelRegisterName->setMinimumSize(QSize(100, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelRegisterName->setFont(font1);
        labelRegisterName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelRegisterName);

        lineEditRegisterName = new QLineEdit(RegisterWindow);
        lineEditRegisterName->setObjectName(QString::fromUtf8("lineEditRegisterName"));
        lineEditRegisterName->setMinimumSize(QSize(350, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditRegisterName->setFont(font2);

        horizontalLayout->addWidget(lineEditRegisterName);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelRegisterPasswd = new QLabel(RegisterWindow);
        labelRegisterPasswd->setObjectName(QString::fromUtf8("labelRegisterPasswd"));
        labelRegisterPasswd->setMinimumSize(QSize(100, 40));
        labelRegisterPasswd->setFont(font1);
        labelRegisterPasswd->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelRegisterPasswd);

        lineEditRegisterPasswd = new QLineEdit(RegisterWindow);
        lineEditRegisterPasswd->setObjectName(QString::fromUtf8("lineEditRegisterPasswd"));
        lineEditRegisterPasswd->setMinimumSize(QSize(350, 40));
        lineEditRegisterPasswd->setFont(font2);

        horizontalLayout_2->addWidget(lineEditRegisterPasswd);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labelRegisterEmail = new QLabel(RegisterWindow);
        labelRegisterEmail->setObjectName(QString::fromUtf8("labelRegisterEmail"));
        labelRegisterEmail->setMinimumSize(QSize(100, 40));
        labelRegisterEmail->setFont(font1);
        labelRegisterEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelRegisterEmail);

        lineEditRegisterEmail = new QLineEdit(RegisterWindow);
        lineEditRegisterEmail->setObjectName(QString::fromUtf8("lineEditRegisterEmail"));
        lineEditRegisterEmail->setMinimumSize(QSize(350, 40));
        lineEditRegisterEmail->setFont(font2);

        horizontalLayout_3->addWidget(lineEditRegisterEmail);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        labelRegisterTelephone = new QLabel(RegisterWindow);
        labelRegisterTelephone->setObjectName(QString::fromUtf8("labelRegisterTelephone"));
        labelRegisterTelephone->setMinimumSize(QSize(100, 40));
        labelRegisterTelephone->setFont(font1);
        labelRegisterTelephone->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRegisterTelephone);

        lineEditRegisterTelephone = new QLineEdit(RegisterWindow);
        lineEditRegisterTelephone->setObjectName(QString::fromUtf8("lineEditRegisterTelephone"));
        lineEditRegisterTelephone->setMinimumSize(QSize(350, 40));
        lineEditRegisterTelephone->setFont(font2);

        horizontalLayout_4->addWidget(lineEditRegisterTelephone);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnRegisterOK = new QPushButton(RegisterWindow);
        btnRegisterOK->setObjectName(QString::fromUtf8("btnRegisterOK"));
        btnRegisterOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_6->addWidget(btnRegisterOK);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QWidget *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Form", nullptr));
        labelRegister->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        labelRegisterName->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelRegisterPasswd->setText(QCoreApplication::translate("RegisterWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelRegisterEmail->setText(QCoreApplication::translate("RegisterWindow", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelRegisterTelephone->setText(QCoreApplication::translate("RegisterWindow", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        btnRegisterOK->setText(QCoreApplication::translate("RegisterWindow", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
