/********************************************************************************
** Form generated from reading UI file 'statusbar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSBAR_H
#define UI_STATUSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusBar
{
public:
    QGridLayout *gridLayout;
    QLabel *labelStatusBar;

    void setupUi(QWidget *StatusBar)
    {
        if (StatusBar->objectName().isEmpty())
            StatusBar->setObjectName(QString::fromUtf8("StatusBar"));
        StatusBar->resize(800, 600);
        gridLayout = new QGridLayout(StatusBar);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelStatusBar = new QLabel(StatusBar);
        labelStatusBar->setObjectName(QString::fromUtf8("labelStatusBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelStatusBar->sizePolicy().hasHeightForWidth());
        labelStatusBar->setSizePolicy(sizePolicy);
        labelStatusBar->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelStatusBar->setFont(font);
        labelStatusBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(labelStatusBar, 0, 0, 1, 1);


        retranslateUi(StatusBar);

        QMetaObject::connectSlotsByName(StatusBar);
    } // setupUi

    void retranslateUi(QWidget *StatusBar)
    {
        StatusBar->setWindowTitle(QCoreApplication::translate("StatusBar", "Form", nullptr));
        labelStatusBar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StatusBar: public Ui_StatusBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSBAR_H
