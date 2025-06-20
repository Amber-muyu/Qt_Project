/********************************************************************************
** Form generated from reading UI file 'serialport.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_H
#define UI_SERIALPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPort
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QLabel *labelBaudRate;
    QComboBox *comboBoxBaudRate;
    QLabel *labelDatabits;
    QComboBox *comboBoxDatabits;
    QLabel *labelParity;
    QComboBox *comboBoxParity;
    QLabel *labelStopbit;
    QComboBox *comboBoxStopbit;
    QLabel *labelFlowctl;
    QComboBox *comboBoxFlowctr;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOpen;
    QGridLayout *gridLayout_3;
    QTextEdit *receiveArea;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *sendArea;
    QPushButton *btnSend;

    void setupUi(QWidget *SerialPort)
    {
        if (SerialPort->objectName().isEmpty())
            SerialPort->setObjectName(QString::fromUtf8("SerialPort"));
        SerialPort->resize(800, 600);
        gridLayout_4 = new QGridLayout(SerialPort);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(SerialPort);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPort = new QLabel(widget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy);
        labelPort->setMinimumSize(QSize(100, 30));
        labelPort->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelPort->setFont(font);
        labelPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPort, 0, 0, 1, 1);

        comboBoxPort = new QComboBox(widget);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        sizePolicy.setHeightForWidth(comboBoxPort->sizePolicy().hasHeightForWidth());
        comboBoxPort->setSizePolicy(sizePolicy);
        comboBoxPort->setMinimumSize(QSize(110, 30));
        comboBoxPort->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxPort, 0, 1, 1, 1);

        labelBaudRate = new QLabel(widget);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        sizePolicy.setHeightForWidth(labelBaudRate->sizePolicy().hasHeightForWidth());
        labelBaudRate->setSizePolicy(sizePolicy);
        labelBaudRate->setMinimumSize(QSize(100, 30));
        labelBaudRate->setMaximumSize(QSize(100, 30));
        labelBaudRate->setFont(font);
        labelBaudRate->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBaudRate, 1, 0, 1, 1);

        comboBoxBaudRate = new QComboBox(widget);
        comboBoxBaudRate->setObjectName(QString::fromUtf8("comboBoxBaudRate"));
        sizePolicy.setHeightForWidth(comboBoxBaudRate->sizePolicy().hasHeightForWidth());
        comboBoxBaudRate->setSizePolicy(sizePolicy);
        comboBoxBaudRate->setMinimumSize(QSize(110, 30));
        comboBoxBaudRate->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxBaudRate, 1, 1, 1, 1);

        labelDatabits = new QLabel(widget);
        labelDatabits->setObjectName(QString::fromUtf8("labelDatabits"));
        sizePolicy.setHeightForWidth(labelDatabits->sizePolicy().hasHeightForWidth());
        labelDatabits->setSizePolicy(sizePolicy);
        labelDatabits->setMinimumSize(QSize(100, 30));
        labelDatabits->setMaximumSize(QSize(100, 30));
        labelDatabits->setFont(font);
        labelDatabits->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDatabits, 2, 0, 1, 1);

        comboBoxDatabits = new QComboBox(widget);
        comboBoxDatabits->setObjectName(QString::fromUtf8("comboBoxDatabits"));
        sizePolicy.setHeightForWidth(comboBoxDatabits->sizePolicy().hasHeightForWidth());
        comboBoxDatabits->setSizePolicy(sizePolicy);
        comboBoxDatabits->setMinimumSize(QSize(110, 30));
        comboBoxDatabits->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxDatabits, 2, 1, 1, 1);

        labelParity = new QLabel(widget);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        sizePolicy.setHeightForWidth(labelParity->sizePolicy().hasHeightForWidth());
        labelParity->setSizePolicy(sizePolicy);
        labelParity->setMinimumSize(QSize(100, 30));
        labelParity->setMaximumSize(QSize(100, 30));
        labelParity->setFont(font);
        labelParity->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelParity, 3, 0, 1, 1);

        comboBoxParity = new QComboBox(widget);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        sizePolicy.setHeightForWidth(comboBoxParity->sizePolicy().hasHeightForWidth());
        comboBoxParity->setSizePolicy(sizePolicy);
        comboBoxParity->setMinimumSize(QSize(110, 30));
        comboBoxParity->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxParity, 3, 1, 1, 1);

        labelStopbit = new QLabel(widget);
        labelStopbit->setObjectName(QString::fromUtf8("labelStopbit"));
        sizePolicy.setHeightForWidth(labelStopbit->sizePolicy().hasHeightForWidth());
        labelStopbit->setSizePolicy(sizePolicy);
        labelStopbit->setMinimumSize(QSize(100, 30));
        labelStopbit->setMaximumSize(QSize(100, 30));
        labelStopbit->setFont(font);
        labelStopbit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelStopbit, 4, 0, 1, 1);

        comboBoxStopbit = new QComboBox(widget);
        comboBoxStopbit->setObjectName(QString::fromUtf8("comboBoxStopbit"));
        sizePolicy.setHeightForWidth(comboBoxStopbit->sizePolicy().hasHeightForWidth());
        comboBoxStopbit->setSizePolicy(sizePolicy);
        comboBoxStopbit->setMinimumSize(QSize(110, 30));
        comboBoxStopbit->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxStopbit, 4, 1, 1, 1);

        labelFlowctl = new QLabel(widget);
        labelFlowctl->setObjectName(QString::fromUtf8("labelFlowctl"));
        sizePolicy.setHeightForWidth(labelFlowctl->sizePolicy().hasHeightForWidth());
        labelFlowctl->setSizePolicy(sizePolicy);
        labelFlowctl->setMinimumSize(QSize(100, 30));
        labelFlowctl->setMaximumSize(QSize(100, 30));
        labelFlowctl->setFont(font);
        labelFlowctl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelFlowctl, 5, 0, 1, 1);

        comboBoxFlowctr = new QComboBox(widget);
        comboBoxFlowctr->setObjectName(QString::fromUtf8("comboBoxFlowctr"));
        sizePolicy.setHeightForWidth(comboBoxFlowctr->sizePolicy().hasHeightForWidth());
        comboBoxFlowctr->setSizePolicy(sizePolicy);
        comboBoxFlowctr->setMinimumSize(QSize(110, 30));
        comboBoxFlowctr->setMaximumSize(QSize(110, 30));

        gridLayout->addWidget(comboBoxFlowctr, 5, 1, 1, 1);


        verticalLayout->addWidget(widget);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOpen = new QPushButton(SerialPort);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        sizePolicy.setHeightForWidth(btnOpen->sizePolicy().hasHeightForWidth());
        btnOpen->setSizePolicy(sizePolicy);
        btnOpen->setFont(font);

        horizontalLayout->addWidget(btnOpen);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        receiveArea = new QTextEdit(SerialPort);
        receiveArea->setObjectName(QString::fromUtf8("receiveArea"));

        gridLayout_3->addWidget(receiveArea, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sendArea = new QTextEdit(SerialPort);
        sendArea->setObjectName(QString::fromUtf8("sendArea"));

        horizontalLayout_2->addWidget(sendArea);

        btnSend = new QPushButton(SerialPort);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setMinimumSize(QSize(0, 87));
        btnSend->setFont(font);

        horizontalLayout_2->addWidget(btnSend);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 100);
        gridLayout_3->setRowStretch(1, 5);

        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 5);
        gridLayout_4->setColumnStretch(1, 110);

        retranslateUi(SerialPort);

        QMetaObject::connectSlotsByName(SerialPort);
    } // setupUi

    void retranslateUi(QWidget *SerialPort)
    {
        SerialPort->setWindowTitle(QCoreApplication::translate("SerialPort", "Form", nullptr));
        labelPort->setText(QCoreApplication::translate("SerialPort", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        labelBaudRate->setText(QCoreApplication::translate("SerialPort", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        labelDatabits->setText(QCoreApplication::translate("SerialPort", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        labelParity->setText(QCoreApplication::translate("SerialPort", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        labelStopbit->setText(QCoreApplication::translate("SerialPort", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        labelFlowctl->setText(QCoreApplication::translate("SerialPort", "\346\265\201\346\216\247\345\210\266\357\274\232", nullptr));
        btnOpen->setText(QCoreApplication::translate("SerialPort", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        btnSend->setText(QCoreApplication::translate("SerialPort", "\345\274\200\345\247\213\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPort: public Ui_SerialPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_H
