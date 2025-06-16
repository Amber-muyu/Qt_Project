/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QLabel *labelLogout;
    QPushButton *btnLogout;

    void setupUi(QWidget *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QString::fromUtf8("HomeWindow"));
        HomeWindow->resize(800, 600);
        labelLogout = new QLabel(HomeWindow);
        labelLogout->setObjectName(QString::fromUtf8("labelLogout"));
        labelLogout->setGeometry(QRect(480, 90, 61, 50));
        labelLogout->setMinimumSize(QSize(50, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelLogout->setFont(font);
        labelLogout->setStyleSheet(QString::fromUtf8("#ForgetLabel[state='normal'],#ForgetLabel[state='selected'] { color: black; }\n"
"#ForgetLabel[state='normal_hover'],#ForgetLabel[state='selected_hover'] { color: rgb(42,112,241); }\n"
""));
        btnLogout = new QPushButton(HomeWindow);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        btnLogout->setGeometry(QRect(640, 100, 93, 61));

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QWidget *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "Form", nullptr));
        labelLogout->setText(QCoreApplication::translate("HomeWindow", "\346\263\250\351\224\200", nullptr));
        btnLogout->setText(QCoreApplication::translate("HomeWindow", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
