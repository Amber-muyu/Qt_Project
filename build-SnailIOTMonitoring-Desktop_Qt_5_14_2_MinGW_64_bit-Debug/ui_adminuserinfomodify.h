/********************************************************************************
** Form generated from reading UI file 'adminuserinfomodify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUSERINFOMODIFY_H
#define UI_ADMINUSERINFOMODIFY_H

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

class Ui_AdminUserInfoModify
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelRole;
    QLineEdit *lineEditModifyRole;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditModifyUserName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelEmail;
    QLineEdit *lineEditModifyEmail;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPhone;
    QLineEdit *lineEditModifyPhone;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelPassword;
    QLineEdit *lineEditModifyPassword;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnInfoModifyOK;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *AdminUserInfoModify)
    {
        if (AdminUserInfoModify->objectName().isEmpty())
            AdminUserInfoModify->setObjectName(QString::fromUtf8("AdminUserInfoModify"));
        AdminUserInfoModify->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminUserInfoModify);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 43, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(AdminUserInfoModify);
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
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRole = new QLabel(AdminUserInfoModify);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));
        labelRole->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labelRole->setFont(font1);
        labelRole->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRole);

        lineEditModifyRole = new QLineEdit(AdminUserInfoModify);
        lineEditModifyRole->setObjectName(QString::fromUtf8("lineEditModifyRole"));
        lineEditModifyRole->setMinimumSize(QSize(350, 50));

        horizontalLayout_4->addWidget(lineEditModifyRole);


        gridLayout_3->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(AdminUserInfoModify);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setMinimumSize(QSize(100, 50));
        labelUserName->setFont(font1);
        labelUserName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelUserName);

        lineEditModifyUserName = new QLineEdit(AdminUserInfoModify);
        lineEditModifyUserName->setObjectName(QString::fromUtf8("lineEditModifyUserName"));
        lineEditModifyUserName->setMinimumSize(QSize(350, 50));

        horizontalLayout->addWidget(lineEditModifyUserName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelEmail = new QLabel(AdminUserInfoModify);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setMinimumSize(QSize(100, 50));
        labelEmail->setFont(font1);
        labelEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelEmail);

        lineEditModifyEmail = new QLineEdit(AdminUserInfoModify);
        lineEditModifyEmail->setObjectName(QString::fromUtf8("lineEditModifyEmail"));
        lineEditModifyEmail->setMinimumSize(QSize(350, 50));

        horizontalLayout_2->addWidget(lineEditModifyEmail);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPhone = new QLabel(AdminUserInfoModify);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setMinimumSize(QSize(100, 50));
        labelPhone->setFont(font1);
        labelPhone->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelPhone);

        lineEditModifyPhone = new QLineEdit(AdminUserInfoModify);
        lineEditModifyPhone->setObjectName(QString::fromUtf8("lineEditModifyPhone"));
        lineEditModifyPhone->setMinimumSize(QSize(350, 50));

        horizontalLayout_3->addWidget(lineEditModifyPhone);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelPassword = new QLabel(AdminUserInfoModify);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        labelPassword->setMinimumSize(QSize(100, 50));
        labelPassword->setFont(font1);
        labelPassword->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelPassword);

        lineEditModifyPassword = new QLineEdit(AdminUserInfoModify);
        lineEditModifyPassword->setObjectName(QString::fromUtf8("lineEditModifyPassword"));
        lineEditModifyPassword->setMinimumSize(QSize(350, 50));

        horizontalLayout_7->addWidget(lineEditModifyPassword);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnInfoModifyOK = new QPushButton(AdminUserInfoModify);
        btnInfoModifyOK->setObjectName(QString::fromUtf8("btnInfoModifyOK"));
        btnInfoModifyOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModifyOK);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(AdminUserInfoModify);

        QMetaObject::connectSlotsByName(AdminUserInfoModify);
    } // setupUi

    void retranslateUi(QWidget *AdminUserInfoModify)
    {
        AdminUserInfoModify->setWindowTitle(QCoreApplication::translate("AdminUserInfoModify", "Form", nullptr));
        label->setText(QCoreApplication::translate("AdminUserInfoModify", "\347\224\250\346\210\267\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        labelRole->setText(QCoreApplication::translate("AdminUserInfoModify", "\350\247\222\350\211\262\357\274\232", nullptr));
        labelUserName->setText(QCoreApplication::translate("AdminUserInfoModify", "\347\224\250\346\210\267\357\274\232", nullptr));
        labelEmail->setText(QCoreApplication::translate("AdminUserInfoModify", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelPhone->setText(QCoreApplication::translate("AdminUserInfoModify", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("AdminUserInfoModify", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnInfoModifyOK->setText(QCoreApplication::translate("AdminUserInfoModify", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUserInfoModify: public Ui_AdminUserInfoModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUSERINFOMODIFY_H
