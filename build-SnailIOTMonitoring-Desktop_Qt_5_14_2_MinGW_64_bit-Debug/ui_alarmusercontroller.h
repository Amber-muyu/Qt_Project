/********************************************************************************
** Form generated from reading UI file 'alarmusercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMUSERCONTROLLER_H
#define UI_ALARMUSERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmUserController
{
public:

    void setupUi(QWidget *AlarmUserController)
    {
        if (AlarmUserController->objectName().isEmpty())
            AlarmUserController->setObjectName(QString::fromUtf8("AlarmUserController"));
        AlarmUserController->resize(800, 600);

        retranslateUi(AlarmUserController);

        QMetaObject::connectSlotsByName(AlarmUserController);
    } // setupUi

    void retranslateUi(QWidget *AlarmUserController)
    {
        AlarmUserController->setWindowTitle(QCoreApplication::translate("AlarmUserController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmUserController: public Ui_AlarmUserController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMUSERCONTROLLER_H
