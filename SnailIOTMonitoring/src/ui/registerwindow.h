#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include "../utils/utils.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

public slots:
    void registerReturnLoginPage();

signals:
    void display(int);
    void sendMessage(const QString&);

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
