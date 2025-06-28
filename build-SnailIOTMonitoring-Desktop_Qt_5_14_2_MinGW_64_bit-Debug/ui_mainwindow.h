/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *titleBarLayout;
    QVBoxLayout *centerLayout;
    QVBoxLayout *statusBarLayout;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 700);
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleBarLayout = new QVBoxLayout();
        titleBarLayout->setObjectName(QString::fromUtf8("titleBarLayout"));

        gridLayout->addLayout(titleBarLayout, 0, 0, 1, 1);

        centerLayout = new QVBoxLayout();
        centerLayout->setObjectName(QString::fromUtf8("centerLayout"));

        gridLayout->addLayout(centerLayout, 1, 0, 1, 1);

        statusBarLayout = new QVBoxLayout();
        statusBarLayout->setObjectName(QString::fromUtf8("statusBarLayout"));

        gridLayout->addLayout(statusBarLayout, 2, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 140);
        gridLayout->setRowStretch(2, 10);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
