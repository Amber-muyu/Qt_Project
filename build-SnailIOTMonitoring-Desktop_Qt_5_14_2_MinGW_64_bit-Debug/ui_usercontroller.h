/********************************************************************************
** Form generated from reading UI file 'usercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCONTROLLER_H
#define UI_USERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserController
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
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
    QPushButton *btnPassWordModify;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *UserController)
    {
        if (UserController->objectName().isEmpty())
            UserController->setObjectName(QString::fromUtf8("UserController"));
        UserController->resize(800, 600);
        gridLayout = new QGridLayout(UserController);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(UserController);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 64, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(UserController);
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

        labelTextUserName = new QLabel(UserController);
        labelTextUserName->setObjectName(QString::fromUtf8("labelTextUserName"));
        labelTextUserName->setMinimumSize(QSize(350, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        labelTextUserName->setFont(font2);
        labelTextUserName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(labelTextUserName);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelEmail = new QLabel(UserController);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));
        labelEmail->setMinimumSize(QSize(100, 50));
        labelEmail->setFont(font1);
        labelEmail->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelEmail);

        labelTextEmail = new QLabel(UserController);
        labelTextEmail->setObjectName(QString::fromUtf8("labelTextEmail"));
        labelTextEmail->setMinimumSize(QSize(350, 50));
        labelTextEmail->setFont(font2);
        labelTextEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(labelTextEmail);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPhone = new QLabel(UserController);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setMinimumSize(QSize(100, 50));
        labelPhone->setFont(font1);
        labelPhone->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelPhone);

        labelTextPhone = new QLabel(UserController);
        labelTextPhone->setObjectName(QString::fromUtf8("labelTextPhone"));
        labelTextPhone->setMinimumSize(QSize(350, 50));
        labelTextPhone->setFont(font2);
        labelTextPhone->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(labelTextPhone);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelRole = new QLabel(UserController);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));
        labelRole->setMinimumSize(QSize(100, 50));
        labelRole->setFont(font1);
        labelRole->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelRole);

        labelTextRole = new QLabel(UserController);
        labelTextRole->setObjectName(QString::fromUtf8("labelTextRole"));
        labelTextRole->setMinimumSize(QSize(350, 50));
        labelTextRole->setFont(font2);
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

        btnInfoModify = new QPushButton(UserController);
        btnInfoModify->setObjectName(QString::fromUtf8("btnInfoModify"));
        btnInfoModify->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnInfoModify);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btnPassWordModify = new QPushButton(UserController);
        btnPassWordModify->setObjectName(QString::fromUtf8("btnPassWordModify"));
        btnPassWordModify->setMinimumSize(QSize(100, 50));

        horizontalLayout_5->addWidget(btnPassWordModify);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_4, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 97, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 3, 1, 1, 1);


        retranslateUi(UserController);

        QMetaObject::connectSlotsByName(UserController);
    } // setupUi

    void retranslateUi(QWidget *UserController)
    {
        UserController->setWindowTitle(QCoreApplication::translate("UserController", "Form", nullptr));
        label->setText(QCoreApplication::translate("UserController", "\347\224\250\346\210\267\344\270\252\344\272\272\344\277\241\346\201\257\346\230\276\347\244\272", nullptr));
        labelUserName->setText(QCoreApplication::translate("UserController", "\347\224\250\346\210\267\357\274\232", nullptr));
        labelTextUserName->setText(QString());
        labelEmail->setText(QCoreApplication::translate("UserController", "\351\202\256\347\256\261\357\274\232", nullptr));
        labelTextEmail->setText(QString());
        labelPhone->setText(QCoreApplication::translate("UserController", "\347\224\265\350\257\235\357\274\232", nullptr));
        labelTextPhone->setText(QString());
        labelRole->setText(QCoreApplication::translate("UserController", "\350\247\222\350\211\262\357\274\232", nullptr));
        labelTextRole->setText(QString());
        btnInfoModify->setText(QCoreApplication::translate("UserController", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        btnPassWordModify->setText(QCoreApplication::translate("UserController", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserController: public Ui_UserController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCONTROLLER_H
