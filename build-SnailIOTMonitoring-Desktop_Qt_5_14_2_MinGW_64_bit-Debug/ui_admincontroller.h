/********************************************************************************
** Form generated from reading UI file 'admincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCONTROLLER_H
#define UI_ADMINCONTROLLER_H

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

class Ui_AdminController
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditSelectUser;
    QPushButton *btnAddUser;
    QPushButton *btnModifyUser;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDeleteUser;
    QLabel *labelSearch;
    QTableView *tableView;

    void setupUi(QWidget *AdminController)
    {
        if (AdminController->objectName().isEmpty())
            AdminController->setObjectName(QString::fromUtf8("AdminController"));
        AdminController->resize(800, 600);
        gridLayout_2 = new QGridLayout(AdminController);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        labelTitle = new QLabel(AdminController);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(AdminController);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditSelectUser = new QLineEdit(widget);
        lineEditSelectUser->setObjectName(QString::fromUtf8("lineEditSelectUser"));
        lineEditSelectUser->setMinimumSize(QSize(210, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditSelectUser->setFont(font1);

        gridLayout->addWidget(lineEditSelectUser, 0, 1, 1, 1);

        btnAddUser = new QPushButton(widget);
        btnAddUser->setObjectName(QString::fromUtf8("btnAddUser"));
        btnAddUser->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnAddUser, 0, 2, 1, 1);

        btnModifyUser = new QPushButton(widget);
        btnModifyUser->setObjectName(QString::fromUtf8("btnModifyUser"));
        btnModifyUser->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnModifyUser, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        btnDeleteUser = new QPushButton(widget);
        btnDeleteUser->setObjectName(QString::fromUtf8("btnDeleteUser"));
        btnDeleteUser->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(btnDeleteUser, 0, 4, 1, 1);

        labelSearch = new QLabel(widget);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        labelSearch->setMinimumSize(QSize(0, 30));
        labelSearch->setFont(font1);
        labelSearch->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSearch, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 2);

        tableView = new QTableView(AdminController);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 2);


        retranslateUi(AdminController);

        QMetaObject::connectSlotsByName(AdminController);
    } // setupUi

    void retranslateUi(QWidget *AdminController)
    {
        AdminController->setWindowTitle(QCoreApplication::translate("AdminController", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("AdminController", "\347\224\250\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        btnAddUser->setText(QCoreApplication::translate("AdminController", "\347\224\250\346\210\267\345\257\274\345\205\245", nullptr));
        btnModifyUser->setText(QCoreApplication::translate("AdminController", "\344\277\256\346\224\271\347\224\250\346\210\267", nullptr));
        btnDeleteUser->setText(QCoreApplication::translate("AdminController", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        labelSearch->setText(QCoreApplication::translate("AdminController", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminController: public Ui_AdminController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCONTROLLER_H
