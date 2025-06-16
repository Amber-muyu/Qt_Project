/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassWord;
    QLineEdit *lineEditPassWord;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelLogin;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditUserName;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnRegister;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnResetPasswd;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(800, 600);
        gridLayout_2 = new QGridLayout(LoginWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(200, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPassWord = new QLabel(LoginWindow);
        labelPassWord->setObjectName(QString::fromUtf8("labelPassWord"));
        labelPassWord->setMinimumSize(QSize(91, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelPassWord->setFont(font1);
        labelPassWord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelPassWord);

        lineEditPassWord = new QLineEdit(LoginWindow);
        lineEditPassWord->setObjectName(QString::fromUtf8("lineEditPassWord"));
        lineEditPassWord->setMinimumSize(QSize(381, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditPassWord->setFont(font2);

        horizontalLayout_2->addWidget(lineEditPassWord);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        labelLogin = new QLabel(LoginWindow);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));
        labelLogin->setMinimumSize(QSize(121, 121));
        labelLogin->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/users.png);"));

        horizontalLayout_5->addWidget(labelLogin);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUserName = new QLabel(LoginWindow);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setMinimumSize(QSize(91, 41));
        labelUserName->setFont(font1);
        labelUserName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelUserName);

        lineEditUserName = new QLineEdit(LoginWindow);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));
        lineEditUserName->setMinimumSize(QSize(381, 41));
        lineEditUserName->setFont(font2);

        horizontalLayout->addWidget(lineEditUserName);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnLogin = new QPushButton(LoginWindow);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMinimumSize(QSize(81, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Arabic"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        btnLogin->setFont(font3);

        horizontalLayout_3->addWidget(btnLogin);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        btnRegister = new QPushButton(LoginWindow);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setMinimumSize(QSize(81, 51));
        btnRegister->setFont(font3);

        horizontalLayout_3->addWidget(btnRegister);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        btnResetPasswd = new QPushButton(LoginWindow);
        btnResetPasswd->setObjectName(QString::fromUtf8("btnResetPasswd"));
        btnResetPasswd->setMinimumSize(QSize(81, 51));
        btnResetPasswd->setFont(font3);

        horizontalLayout_3->addWidget(btnResetPasswd);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        labelPassWord->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelLogin->setText(QString());
        labelUserName->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\357\274\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
        btnRegister->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214", nullptr));
        btnResetPasswd->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
