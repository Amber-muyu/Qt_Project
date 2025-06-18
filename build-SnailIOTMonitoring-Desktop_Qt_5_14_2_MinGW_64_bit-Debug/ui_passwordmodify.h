/********************************************************************************
** Form generated from reading UI file 'passwordmodify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDMODIFY_H
#define UI_PASSWORDMODIFY_H

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

class Ui_PasswordModify
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelEmail;
    QLineEdit *lineEditModifyOldPassword;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPhone;
    QLineEdit *lineEditModifyNewPassword;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditModifyUserName;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnPassWordModifyOK;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *PasswordModify)
    {
        if (PasswordModify->objectName().isEmpty())
            PasswordModify->setObjectName(QString::fromUtf8("PasswordModify"));
        PasswordModify->resize(800, 600);
        gridLayout_2 = new QGridLayout(PasswordModify);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(PasswordModify);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(220, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelEmail = new QLabel(PasswordModify);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        labelEmail->setFont(font1);
        labelEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelEmail);

        lineEditModifyOldPassword = new QLineEdit(PasswordModify);
        lineEditModifyOldPassword->setObjectName(QString::fromUtf8("lineEditModifyOldPassword"));
        lineEditModifyOldPassword->setMinimumSize(QSize(350, 50));

        horizontalLayout_2->addWidget(lineEditModifyOldPassword);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPhone = new QLabel(PasswordModify);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setMinimumSize(QSize(100, 50));
        labelPhone->setFont(font1);
        labelPhone->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelPhone);

        lineEditModifyNewPassword = new QLineEdit(PasswordModify);
        lineEditModifyNewPassword->setObjectName(QString::fromUtf8("lineEditModifyNewPassword"));
        lineEditModifyNewPassword->setMinimumSize(QSize(350, 50));

        horizontalLayout_3->addWidget(lineEditModifyNewPassword);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(PasswordModify);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setMinimumSize(QSize(100, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        labelUserName->setFont(font2);
        labelUserName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelUserName);

        lineEditModifyUserName = new QLineEdit(PasswordModify);
        lineEditModifyUserName->setObjectName(QString::fromUtf8("lineEditModifyUserName"));
        lineEditModifyUserName->setMinimumSize(QSize(350, 50));

        horizontalLayout->addWidget(lineEditModifyUserName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        gridLayout_3->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 6, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnPassWordModifyOK = new QPushButton(PasswordModify);
        btnPassWordModifyOK->setObjectName(QString::fromUtf8("btnPassWordModifyOK"));
        btnPassWordModifyOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnPassWordModifyOK);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);


        retranslateUi(PasswordModify);

        QMetaObject::connectSlotsByName(PasswordModify);
    } // setupUi

    void retranslateUi(QWidget *PasswordModify)
    {
        PasswordModify->setWindowTitle(QCoreApplication::translate("PasswordModify", "Form", nullptr));
        label->setText(QCoreApplication::translate("PasswordModify", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        labelEmail->setText(QCoreApplication::translate("PasswordModify", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        labelPhone->setText(QCoreApplication::translate("PasswordModify", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        labelUserName->setText(QCoreApplication::translate("PasswordModify", "\347\224\250\346\210\267\357\274\232", nullptr));
        btnPassWordModifyOK->setText(QCoreApplication::translate("PasswordModify", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordModify: public Ui_PasswordModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMODIFY_H
