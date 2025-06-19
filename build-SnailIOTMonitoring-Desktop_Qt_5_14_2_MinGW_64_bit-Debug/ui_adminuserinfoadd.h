/********************************************************************************
** Form generated from reading UI file 'adminuserinfoadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUSERINFOADD_H
#define UI_ADMINUSERINFOADD_H

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

class Ui_AdminUserInfoAdd
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelAdd;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelAddName;
    QLineEdit *lineEditAddName;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelAddPasswd;
    QLineEdit *lineEditAddPasswd;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelAddEmail;
    QLineEdit *lineEditAddEmail;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelAddTelephone;
    QLineEdit *lineEditAddTelephone;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddOK;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *AdminUserInfoAdd)
    {
        if (AdminUserInfoAdd->objectName().isEmpty())
            AdminUserInfoAdd->setObjectName(QString::fromUtf8("AdminUserInfoAdd"));
        AdminUserInfoAdd->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminUserInfoAdd);
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

        labelAdd = new QLabel(AdminUserInfoAdd);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setMinimumSize(QSize(200, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        labelAdd->setFont(font);
        labelAdd->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelAdd);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelAddName = new QLabel(AdminUserInfoAdd);
        labelAddName->setObjectName(QString::fromUtf8("labelAddName"));
        labelAddName->setMinimumSize(QSize(100, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelAddName->setFont(font1);
        labelAddName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelAddName);

        lineEditAddName = new QLineEdit(AdminUserInfoAdd);
        lineEditAddName->setObjectName(QString::fromUtf8("lineEditAddName"));
        lineEditAddName->setMinimumSize(QSize(350, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditAddName->setFont(font2);

        horizontalLayout->addWidget(lineEditAddName);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelAddPasswd = new QLabel(AdminUserInfoAdd);
        labelAddPasswd->setObjectName(QString::fromUtf8("labelAddPasswd"));
        labelAddPasswd->setMinimumSize(QSize(100, 40));
        labelAddPasswd->setFont(font1);
        labelAddPasswd->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelAddPasswd);

        lineEditAddPasswd = new QLineEdit(AdminUserInfoAdd);
        lineEditAddPasswd->setObjectName(QString::fromUtf8("lineEditAddPasswd"));
        lineEditAddPasswd->setMinimumSize(QSize(350, 40));
        lineEditAddPasswd->setFont(font2);

        horizontalLayout_2->addWidget(lineEditAddPasswd);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labelAddEmail = new QLabel(AdminUserInfoAdd);
        labelAddEmail->setObjectName(QString::fromUtf8("labelAddEmail"));
        labelAddEmail->setMinimumSize(QSize(100, 40));
        labelAddEmail->setFont(font1);
        labelAddEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelAddEmail);

        lineEditAddEmail = new QLineEdit(AdminUserInfoAdd);
        lineEditAddEmail->setObjectName(QString::fromUtf8("lineEditAddEmail"));
        lineEditAddEmail->setMinimumSize(QSize(350, 40));
        lineEditAddEmail->setFont(font2);

        horizontalLayout_3->addWidget(lineEditAddEmail);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        labelAddTelephone = new QLabel(AdminUserInfoAdd);
        labelAddTelephone->setObjectName(QString::fromUtf8("labelAddTelephone"));
        labelAddTelephone->setMinimumSize(QSize(100, 40));
        labelAddTelephone->setFont(font1);
        labelAddTelephone->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelAddTelephone);

        lineEditAddTelephone = new QLineEdit(AdminUserInfoAdd);
        lineEditAddTelephone->setObjectName(QString::fromUtf8("lineEditAddTelephone"));
        lineEditAddTelephone->setMinimumSize(QSize(350, 40));
        lineEditAddTelephone->setFont(font2);

        horizontalLayout_4->addWidget(lineEditAddTelephone);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnAddOK = new QPushButton(AdminUserInfoAdd);
        btnAddOK->setObjectName(QString::fromUtf8("btnAddOK"));
        btnAddOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_6->addWidget(btnAddOK);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 7, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(AdminUserInfoAdd);

        QMetaObject::connectSlotsByName(AdminUserInfoAdd);
    } // setupUi

    void retranslateUi(QWidget *AdminUserInfoAdd)
    {
        AdminUserInfoAdd->setWindowTitle(QCoreApplication::translate("AdminUserInfoAdd", "Form", nullptr));
        labelAdd->setText(QCoreApplication::translate("AdminUserInfoAdd", "\346\226\260\345\242\236\347\224\250\346\210\267", nullptr));
        labelAddName->setText(QCoreApplication::translate("AdminUserInfoAdd", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelAddPasswd->setText(QCoreApplication::translate("AdminUserInfoAdd", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelAddEmail->setText(QCoreApplication::translate("AdminUserInfoAdd", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelAddTelephone->setText(QCoreApplication::translate("AdminUserInfoAdd", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        btnAddOK->setText(QCoreApplication::translate("AdminUserInfoAdd", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUserInfoAdd: public Ui_AdminUserInfoAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUSERINFOADD_H
