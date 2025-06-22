/********************************************************************************
** Form generated from reading UI file 'adminrulemodify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINRULEMODIFY_H
#define UI_ADMINRULEMODIFY_H

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

class Ui_AdminRuleModify
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelModifyAction;
    QLineEdit *lineEditModifyAction;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnModifyOK;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelModifyID;
    QLineEdit *lineEditModifyID;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelModify;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelModifyCondition;
    QLineEdit *lineEditModifyCondition;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelModifyDescription;
    QLineEdit *lineEditModifyDescription;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *AdminRuleModify)
    {
        if (AdminRuleModify->objectName().isEmpty())
            AdminRuleModify->setObjectName(QString::fromUtf8("AdminRuleModify"));
        AdminRuleModify->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminRuleModify);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        labelModifyAction = new QLabel(AdminRuleModify);
        labelModifyAction->setObjectName(QString::fromUtf8("labelModifyAction"));
        labelModifyAction->setMinimumSize(QSize(100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelModifyAction->setFont(font);
        labelModifyAction->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelModifyAction);

        lineEditModifyAction = new QLineEdit(AdminRuleModify);
        lineEditModifyAction->setObjectName(QString::fromUtf8("lineEditModifyAction"));
        lineEditModifyAction->setMinimumSize(QSize(350, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditModifyAction->setFont(font1);

        horizontalLayout_4->addWidget(lineEditModifyAction);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnModifyOK = new QPushButton(AdminRuleModify);
        btnModifyOK->setObjectName(QString::fromUtf8("btnModifyOK"));
        btnModifyOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_6->addWidget(btnModifyOK);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelModifyID = new QLabel(AdminRuleModify);
        labelModifyID->setObjectName(QString::fromUtf8("labelModifyID"));
        labelModifyID->setMinimumSize(QSize(100, 40));
        labelModifyID->setFont(font);
        labelModifyID->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelModifyID);

        lineEditModifyID = new QLineEdit(AdminRuleModify);
        lineEditModifyID->setObjectName(QString::fromUtf8("lineEditModifyID"));
        lineEditModifyID->setMinimumSize(QSize(350, 40));
        lineEditModifyID->setFont(font1);

        horizontalLayout->addWidget(lineEditModifyID);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelModify = new QLabel(AdminRuleModify);
        labelModify->setObjectName(QString::fromUtf8("labelModify"));
        labelModify->setMinimumSize(QSize(200, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        labelModify->setFont(font2);
        labelModify->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelModify);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labelModifyCondition = new QLabel(AdminRuleModify);
        labelModifyCondition->setObjectName(QString::fromUtf8("labelModifyCondition"));
        labelModifyCondition->setMinimumSize(QSize(100, 40));
        labelModifyCondition->setFont(font);
        labelModifyCondition->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelModifyCondition);

        lineEditModifyCondition = new QLineEdit(AdminRuleModify);
        lineEditModifyCondition->setObjectName(QString::fromUtf8("lineEditModifyCondition"));
        lineEditModifyCondition->setMinimumSize(QSize(350, 40));
        lineEditModifyCondition->setFont(font1);

        horizontalLayout_3->addWidget(lineEditModifyCondition);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelModifyDescription = new QLabel(AdminRuleModify);
        labelModifyDescription->setObjectName(QString::fromUtf8("labelModifyDescription"));
        labelModifyDescription->setMinimumSize(QSize(100, 40));
        labelModifyDescription->setFont(font);
        labelModifyDescription->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelModifyDescription);

        lineEditModifyDescription = new QLineEdit(AdminRuleModify);
        lineEditModifyDescription->setObjectName(QString::fromUtf8("lineEditModifyDescription"));
        lineEditModifyDescription->setMinimumSize(QSize(350, 40));
        lineEditModifyDescription->setFont(font1);

        horizontalLayout_2->addWidget(lineEditModifyDescription);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(AdminRuleModify);

        QMetaObject::connectSlotsByName(AdminRuleModify);
    } // setupUi

    void retranslateUi(QWidget *AdminRuleModify)
    {
        AdminRuleModify->setWindowTitle(QCoreApplication::translate("AdminRuleModify", "Form", nullptr));
        labelModifyAction->setText(QCoreApplication::translate("AdminRuleModify", "\351\200\232\347\237\245\346\226\271\345\274\217\357\274\232", nullptr));
        btnModifyOK->setText(QCoreApplication::translate("AdminRuleModify", "\347\241\256\350\256\244", nullptr));
        labelModifyID->setText(QCoreApplication::translate("AdminRuleModify", "\350\256\276\345\244\207ID\357\274\232", nullptr));
        labelModify->setText(QCoreApplication::translate("AdminRuleModify", "\350\247\204\345\210\231\344\277\256\346\224\271", nullptr));
        labelModifyCondition->setText(QCoreApplication::translate("AdminRuleModify", "\350\247\246\345\217\221\346\235\241\344\273\266\357\274\232", nullptr));
        labelModifyDescription->setText(QCoreApplication::translate("AdminRuleModify", "\350\247\204\345\210\231\346\217\217\350\277\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminRuleModify: public Ui_AdminRuleModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINRULEMODIFY_H
