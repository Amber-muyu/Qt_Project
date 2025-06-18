/********************************************************************************
** Form generated from reading UI file 'usermodify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMODIFY_H
#define UI_USERMODIFY_H

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

class Ui_UserModify
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditModifyUserName;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelEmail;
    QLineEdit *lineEditModifyEmail;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPhone;
    QLineEdit *lineEditModifyPhone;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelRole;
    QLineEdit *lineEditModifyRole;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnInfoModifyOK;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QWidget *UserModify)
    {
        if (UserModify->objectName().isEmpty())
            UserModify->setObjectName(QString::fromUtf8("UserModify"));
        UserModify->resize(800, 600);
        gridLayout_2 = new QGridLayout(UserModify);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label = new QLabel(UserModify);
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
        labelUserName = new QLabel(UserModify);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labelUserName->setFont(font1);
        labelUserName->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelUserName);

        lineEditModifyUserName = new QLineEdit(UserModify);
        lineEditModifyUserName->setObjectName(QString::fromUtf8("lineEditModifyUserName"));
        lineEditModifyUserName->setMinimumSize(QSize(350, 50));

        horizontalLayout->addWidget(lineEditModifyUserName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelEmail = new QLabel(UserModify);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setMinimumSize(QSize(100, 50));
        labelEmail->setFont(font1);
        labelEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelEmail);

        lineEditModifyEmail = new QLineEdit(UserModify);
        lineEditModifyEmail->setObjectName(QString::fromUtf8("lineEditModifyEmail"));
        lineEditModifyEmail->setMinimumSize(QSize(350, 50));

        horizontalLayout_2->addWidget(lineEditModifyEmail);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPhone = new QLabel(UserModify);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setMinimumSize(QSize(100, 50));
        labelPhone->setFont(font1);
        labelPhone->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelPhone);

        lineEditModifyPhone = new QLineEdit(UserModify);
        lineEditModifyPhone->setObjectName(QString::fromUtf8("lineEditModifyPhone"));
        lineEditModifyPhone->setMinimumSize(QSize(350, 50));

        horizontalLayout_3->addWidget(lineEditModifyPhone);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRole = new QLabel(UserModify);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));
        labelRole->setMinimumSize(QSize(100, 50));
        labelRole->setFont(font1);
        labelRole->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRole);

        lineEditModifyRole = new QLineEdit(UserModify);
        lineEditModifyRole->setObjectName(QString::fromUtf8("lineEditModifyRole"));
        lineEditModifyRole->setMinimumSize(QSize(350, 50));

        horizontalLayout_4->addWidget(lineEditModifyRole);


        gridLayout_3->addLayout(horizontalLayout_4, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 7, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnInfoModifyOK = new QPushButton(UserModify);
        btnInfoModifyOK->setObjectName(QString::fromUtf8("btnInfoModifyOK"));
        btnInfoModifyOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModifyOK);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 1, 1, 1);


        retranslateUi(UserModify);

        QMetaObject::connectSlotsByName(UserModify);
    } // setupUi

    void retranslateUi(QWidget *UserModify)
    {
        UserModify->setWindowTitle(QCoreApplication::translate("UserModify", "Form", nullptr));
        label->setText(QCoreApplication::translate("UserModify", "\344\270\252\344\272\272\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        labelUserName->setText(QCoreApplication::translate("UserModify", "\347\224\250\346\210\267\357\274\232", nullptr));
        labelEmail->setText(QCoreApplication::translate("UserModify", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelPhone->setText(QCoreApplication::translate("UserModify", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelRole->setText(QCoreApplication::translate("UserModify", "\350\247\222\350\211\262\357\274\232", nullptr));
        btnInfoModifyOK->setText(QCoreApplication::translate("UserModify", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserModify: public Ui_UserModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMODIFY_H
