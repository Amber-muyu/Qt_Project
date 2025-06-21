/********************************************************************************
** Form generated from reading UI file 'adminruleadd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINRULEADD_H
#define UI_ADMINRULEADD_H

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

class Ui_AdminRuleAdd
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelAddAction;
    QLineEdit *lineEditAddAction;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddOK;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelAddID;
    QLineEdit *lineEditAddID;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelAdd;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *labelAddCondition;
    QLineEdit *lineEditAddCondition;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *labelAddDescription;
    QLineEdit *lineEditAddDescription;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *AdminRuleAdd)
    {
        if (AdminRuleAdd->objectName().isEmpty())
            AdminRuleAdd->setObjectName(QString::fromUtf8("AdminRuleAdd"));
        AdminRuleAdd->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminRuleAdd);
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

        labelAddAction = new QLabel(AdminRuleAdd);
        labelAddAction->setObjectName(QString::fromUtf8("labelAddAction"));
        labelAddAction->setMinimumSize(QSize(100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelAddAction->setFont(font);
        labelAddAction->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelAddAction);

        lineEditAddAction = new QLineEdit(AdminRuleAdd);
        lineEditAddAction->setObjectName(QString::fromUtf8("lineEditAddAction"));
        lineEditAddAction->setMinimumSize(QSize(350, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditAddAction->setFont(font1);

        horizontalLayout_4->addWidget(lineEditAddAction);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnAddOK = new QPushButton(AdminRuleAdd);
        btnAddOK->setObjectName(QString::fromUtf8("btnAddOK"));
        btnAddOK->setMinimumSize(QSize(100, 50));

        horizontalLayout_6->addWidget(btnAddOK);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_6, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        labelAddID = new QLabel(AdminRuleAdd);
        labelAddID->setObjectName(QString::fromUtf8("labelAddID"));
        labelAddID->setMinimumSize(QSize(100, 40));
        labelAddID->setFont(font);
        labelAddID->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelAddID);

        lineEditAddID = new QLineEdit(AdminRuleAdd);
        lineEditAddID->setObjectName(QString::fromUtf8("lineEditAddID"));
        lineEditAddID->setMinimumSize(QSize(350, 40));
        lineEditAddID->setFont(font1);

        horizontalLayout->addWidget(lineEditAddID);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelAdd = new QLabel(AdminRuleAdd);
        labelAdd->setObjectName(QString::fromUtf8("labelAdd"));
        labelAdd->setMinimumSize(QSize(200, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Arabic"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        labelAdd->setFont(font2);
        labelAdd->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelAdd);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        labelAddCondition = new QLabel(AdminRuleAdd);
        labelAddCondition->setObjectName(QString::fromUtf8("labelAddCondition"));
        labelAddCondition->setMinimumSize(QSize(100, 40));
        labelAddCondition->setFont(font);
        labelAddCondition->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelAddCondition);

        lineEditAddCondition = new QLineEdit(AdminRuleAdd);
        lineEditAddCondition->setObjectName(QString::fromUtf8("lineEditAddCondition"));
        lineEditAddCondition->setMinimumSize(QSize(350, 40));
        lineEditAddCondition->setFont(font1);

        horizontalLayout_3->addWidget(lineEditAddCondition);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        labelAddDescription = new QLabel(AdminRuleAdd);
        labelAddDescription->setObjectName(QString::fromUtf8("labelAddDescription"));
        labelAddDescription->setMinimumSize(QSize(100, 40));
        labelAddDescription->setFont(font);
        labelAddDescription->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelAddDescription);

        lineEditAddDescription = new QLineEdit(AdminRuleAdd);
        lineEditAddDescription->setObjectName(QString::fromUtf8("lineEditAddDescription"));
        lineEditAddDescription->setMinimumSize(QSize(350, 40));
        lineEditAddDescription->setFont(font1);

        horizontalLayout_2->addWidget(lineEditAddDescription);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(AdminRuleAdd);

        QMetaObject::connectSlotsByName(AdminRuleAdd);
    } // setupUi

    void retranslateUi(QWidget *AdminRuleAdd)
    {
        AdminRuleAdd->setWindowTitle(QCoreApplication::translate("AdminRuleAdd", "Form", nullptr));
        labelAddAction->setText(QCoreApplication::translate("AdminRuleAdd", "\351\200\232\347\237\245\346\226\271\345\274\217\357\274\232", nullptr));
        btnAddOK->setText(QCoreApplication::translate("AdminRuleAdd", "\347\241\256\350\256\244", nullptr));
        labelAddID->setText(QCoreApplication::translate("AdminRuleAdd", "\350\256\276\345\244\207ID\357\274\232", nullptr));
        labelAdd->setText(QCoreApplication::translate("AdminRuleAdd", "\346\226\260\345\242\236\350\247\204\345\210\231", nullptr));
        labelAddCondition->setText(QCoreApplication::translate("AdminRuleAdd", "\350\247\246\345\217\221\346\235\241\344\273\266\357\274\232", nullptr));
        labelAddDescription->setText(QCoreApplication::translate("AdminRuleAdd", "\350\247\204\345\210\231\346\217\217\350\277\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminRuleAdd: public Ui_AdminRuleAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINRULEADD_H
