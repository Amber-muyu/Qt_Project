/********************************************************************************
** Form generated from reading UI file 'datausercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAUSERCONTROLLER_H
#define UI_DATAUSERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataUserController
{
public:

    void setupUi(QWidget *DataUserController)
    {
        if (DataUserController->objectName().isEmpty())
            DataUserController->setObjectName(QString::fromUtf8("DataUserController"));
        DataUserController->resize(800, 600);

        retranslateUi(DataUserController);

        QMetaObject::connectSlotsByName(DataUserController);
    } // setupUi

    void retranslateUi(QWidget *DataUserController)
    {
        DataUserController->setWindowTitle(QCoreApplication::translate("DataUserController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataUserController: public Ui_DataUserController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAUSERCONTROLLER_H
