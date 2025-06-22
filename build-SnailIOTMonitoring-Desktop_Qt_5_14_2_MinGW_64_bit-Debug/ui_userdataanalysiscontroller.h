/********************************************************************************
** Form generated from reading UI file 'userdataanalysiscontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDATAANALYSISCONTROLLER_H
#define UI_USERDATAANALYSISCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDataAnalysisController
{
public:

    void setupUi(QWidget *UserDataAnalysisController)
    {
        if (UserDataAnalysisController->objectName().isEmpty())
            UserDataAnalysisController->setObjectName(QString::fromUtf8("UserDataAnalysisController"));
        UserDataAnalysisController->resize(800, 600);

        retranslateUi(UserDataAnalysisController);

        QMetaObject::connectSlotsByName(UserDataAnalysisController);
    } // setupUi

    void retranslateUi(QWidget *UserDataAnalysisController)
    {
        UserDataAnalysisController->setWindowTitle(QCoreApplication::translate("UserDataAnalysisController", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDataAnalysisController: public Ui_UserDataAnalysisController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDATAANALYSISCONTROLLER_H
