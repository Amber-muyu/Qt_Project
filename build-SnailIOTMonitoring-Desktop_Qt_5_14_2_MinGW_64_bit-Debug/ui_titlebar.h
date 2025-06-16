/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QString::fromUtf8("TitleBar"));
        TitleBar->resize(800, 600);
        gridLayout = new QGridLayout(TitleBar);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(TitleBar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(31, 31));
        label_2->setMaximumSize(QSize(31, 31));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/student.png);"));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(TitleBar);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(301, 31));
        label->setMaximumSize(QSize(301, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnMin = new QPushButton(TitleBar);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        sizePolicy.setHeightForWidth(btnMin->sizePolicy().hasHeightForWidth());
        btnMin->setSizePolicy(sizePolicy);
        btnMin->setMinimumSize(QSize(31, 31));
        btnMin->setMaximumSize(QSize(31, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setWeight(50);
        btnMin->setFont(font1);
        btnMin->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnMin);

        btnMax = new QPushButton(TitleBar);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        sizePolicy.setHeightForWidth(btnMax->sizePolicy().hasHeightForWidth());
        btnMax->setSizePolicy(sizePolicy);
        btnMax->setMinimumSize(QSize(31, 31));
        btnMax->setMaximumSize(QSize(31, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Unicode MS"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        btnMax->setFont(font2);
        btnMax->setLayoutDirection(Qt::LeftToRight);
        btnMax->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnMax);

        btnClose = new QPushButton(TitleBar);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        sizePolicy.setHeightForWidth(btnClose->sizePolicy().hasHeightForWidth());
        btnClose->setSizePolicy(sizePolicy);
        btnClose->setMinimumSize(QSize(31, 31));
        btnClose->setMaximumSize(QSize(31, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Arabic"));
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setWeight(50);
        btnClose->setFont(font3);
        btnClose->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnClose);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);


        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QCoreApplication::translate("TitleBar", "Form", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("TitleBar", "\350\234\227\347\211\233\347\211\251\350\201\224\347\275\221\347\233\221\346\216\247\345\271\263\345\217\260", nullptr));
        btnMin->setText(QCoreApplication::translate("TitleBar", "-", nullptr));
        btnMax->setText(QCoreApplication::translate("TitleBar", "\342\226\241", nullptr));
        btnClose->setText(QCoreApplication::translate("TitleBar", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
