/********************************************************************************
** Form generated from reading UI file 'alarmadmincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMADMINCONTROLLER_H
#define UI_ALARMADMINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmAdminController
{
public:
    QGridLayout *gridLayout_3;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnAddRule;
    QPushButton *btnDeleteRule;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnModifyRule;
    QTableView *tableViewRule;
    QLabel *labelTitle_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnDeleteRecord;
    QLabel *labelSearch;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditSelectRecord;
    QPushButton *btnHandleRecord;
    QTableView *tableViewRecord;

    void setupUi(QWidget *AlarmAdminController)
    {
        if (AlarmAdminController->objectName().isEmpty())
            AlarmAdminController->setObjectName(QString::fromUtf8("AlarmAdminController"));
        AlarmAdminController->resize(800, 600);
        gridLayout_3 = new QGridLayout(AlarmAdminController);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        labelTitle = new QLabel(AlarmAdminController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_3->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(AlarmAdminController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        btnAddRule = new QPushButton(widget);
        btnAddRule->setObjectName(QString::fromUtf8("btnAddRule"));
        btnAddRule->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnAddRule, 0, 0, 1, 1);

        btnDeleteRule = new QPushButton(widget);
        btnDeleteRule->setObjectName(QString::fromUtf8("btnDeleteRule"));
        btnDeleteRule->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDeleteRule, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        btnModifyRule = new QPushButton(widget);
        btnModifyRule->setObjectName(QString::fromUtf8("btnModifyRule"));
        btnModifyRule->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnModifyRule, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);

        tableViewRule = new QTableView(AlarmAdminController);
        tableViewRule->setObjectName(QString::fromUtf8("tableViewRule"));

        gridLayout_3->addWidget(tableViewRule, 2, 0, 1, 1);

        labelTitle_2 = new QLabel(AlarmAdminController);
        labelTitle_2->setObjectName(QString::fromUtf8("labelTitle_2"));
        labelTitle_2->setFont(font);

        gridLayout_3->addWidget(labelTitle_2, 3, 0, 1, 1);

        widget_2 = new QWidget(AlarmAdminController);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        btnDeleteRecord = new QPushButton(widget_2);
        btnDeleteRecord->setObjectName(QString::fromUtf8("btnDeleteRecord"));
        btnDeleteRecord->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(btnDeleteRecord, 0, 2, 1, 1);

        labelSearch = new QLabel(widget_2);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        labelSearch->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelSearch->setFont(font1);
        labelSearch->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelSearch, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        lineEditSelectRecord = new QLineEdit(widget_2);
        lineEditSelectRecord->setObjectName(QString::fromUtf8("lineEditSelectRecord"));
        lineEditSelectRecord->setMinimumSize(QSize(210, 30));
        lineEditSelectRecord->setFont(font1);

        gridLayout_2->addWidget(lineEditSelectRecord, 0, 1, 1, 1);

        btnHandleRecord = new QPushButton(widget_2);
        btnHandleRecord->setObjectName(QString::fromUtf8("btnHandleRecord"));
        btnHandleRecord->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(btnHandleRecord, 0, 3, 1, 1);


        gridLayout_3->addWidget(widget_2, 4, 0, 1, 1);

        tableViewRecord = new QTableView(AlarmAdminController);
        tableViewRecord->setObjectName(QString::fromUtf8("tableViewRecord"));

        gridLayout_3->addWidget(tableViewRecord, 5, 0, 1, 1);


        retranslateUi(AlarmAdminController);

        QMetaObject::connectSlotsByName(AlarmAdminController);
    } // setupUi

    void retranslateUi(QWidget *AlarmAdminController)
    {
        AlarmAdminController->setWindowTitle(QCoreApplication::translate("AlarmAdminController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("AlarmAdminController", "\350\255\246\345\221\212\350\247\204\345\210\231\347\256\241\347\220\206", nullptr));
        btnAddRule->setText(QCoreApplication::translate("AlarmAdminController", "\346\226\260\345\242\236\350\247\204\345\210\231", nullptr));
        btnDeleteRule->setText(QCoreApplication::translate("AlarmAdminController", "\345\210\240\351\231\244\350\247\204\345\210\231", nullptr));
        btnModifyRule->setText(QCoreApplication::translate("AlarmAdminController", "\347\274\226\350\276\221\350\247\204\345\210\231", nullptr));
        labelTitle_2->setText(QCoreApplication::translate("AlarmAdminController", "\350\255\246\345\221\212\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        btnDeleteRecord->setText(QCoreApplication::translate("AlarmAdminController", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        labelSearch->setText(QCoreApplication::translate("AlarmAdminController", "\346\220\234\347\264\242", nullptr));
        btnHandleRecord->setText(QCoreApplication::translate("AlarmAdminController", "\346\266\210\346\201\257\351\200\232\347\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmAdminController: public Ui_AlarmAdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMADMINCONTROLLER_H
