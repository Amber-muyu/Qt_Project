/********************************************************************************
** Form generated from reading UI file 'resetpasswdwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWDWINDOW_H
#define UI_RESETPASSWDWINDOW_H

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

class Ui_ResetPasswdWindow
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnResetPasswdOK;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnReturn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelResetPasswd;
    QLineEdit *lineEditResetPasswd;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *ResetPasswdWindow)
    {
        if (ResetPasswdWindow->objectName().isEmpty())
            ResetPasswdWindow->setObjectName(QString::fromUtf8("ResetPasswdWindow"));
        ResetPasswdWindow->resize(900, 700);
        gridLayout_3 = new QGridLayout(ResetPasswdWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ResetPasswdWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnResetPasswdOK = new QPushButton(ResetPasswdWindow);
        btnResetPasswdOK->setObjectName(QString::fromUtf8("btnResetPasswdOK"));
        btnResetPasswdOK->setMinimumSize(QSize(100, 50));

        horizontalLayout->addWidget(btnResetPasswdOK);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btnReturn = new QPushButton(ResetPasswdWindow);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setMinimumSize(QSize(100, 50));

        horizontalLayout->addWidget(btnReturn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        labelResetPasswd = new QLabel(ResetPasswdWindow);
        labelResetPasswd->setObjectName(QString::fromUtf8("labelResetPasswd"));
        labelResetPasswd->setMinimumSize(QSize(300, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        labelResetPasswd->setFont(font1);

        gridLayout->addWidget(labelResetPasswd, 0, 0, 1, 1);

        lineEditResetPasswd = new QLineEdit(ResetPasswdWindow);
        lineEditResetPasswd->setObjectName(QString::fromUtf8("lineEditResetPasswd"));
        lineEditResetPasswd->setMinimumSize(QSize(350, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditResetPasswd->setFont(font2);

        gridLayout->addWidget(lineEditResetPasswd, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(198, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 131, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(ResetPasswdWindow);

        QMetaObject::connectSlotsByName(ResetPasswdWindow);
    } // setupUi

    void retranslateUi(QWidget *ResetPasswdWindow)
    {
        ResetPasswdWindow->setWindowTitle(QCoreApplication::translate("ResetPasswdWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("ResetPasswdWindow", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        btnResetPasswdOK->setText(QCoreApplication::translate("ResetPasswdWindow", "\347\241\256\350\256\244", nullptr));
        btnReturn->setText(QCoreApplication::translate("ResetPasswdWindow", "\350\277\224\345\233\236", nullptr));
        labelResetPasswd->setText(QCoreApplication::translate("ResetPasswdWindow", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\351\202\256\347\256\261\346\210\226\350\200\205\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPasswdWindow: public Ui_ResetPasswdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWDWINDOW_H
