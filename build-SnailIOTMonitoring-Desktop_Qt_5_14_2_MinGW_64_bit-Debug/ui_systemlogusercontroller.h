/********************************************************************************
** Form generated from reading UI file 'systemlogusercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMLOGUSERCONTROLLER_H
#define UI_SYSTEMLOGUSERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemLogUserController
{
public:

    void setupUi(QWidget *SystemLogUserController)
    {
        if (SystemLogUserController->objectName().isEmpty())
            SystemLogUserController->setObjectName(QString::fromUtf8("SystemLogUserController"));
        SystemLogUserController->resize(800, 600);

        retranslateUi(SystemLogUserController);

        QMetaObject::connectSlotsByName(SystemLogUserController);
    } // setupUi

    void retranslateUi(QWidget *SystemLogUserController)
    {
        SystemLogUserController->setWindowTitle(QCoreApplication::translate("SystemLogUserController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemLogUserController: public Ui_SystemLogUserController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMLOGUSERCONTROLLER_H
