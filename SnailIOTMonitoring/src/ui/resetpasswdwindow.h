#ifndef RESETPASSWDWINDOW_H
#define RESETPASSWDWINDOW_H

#include <QWidget>
#include "../utils/utils.h"
#include "../database/usermanager.h"

namespace Ui {
class ResetPasswdWindow;
}

class ResetPasswdWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPasswdWindow(QWidget *parent = nullptr);
    ~ResetPasswdWindow();

public slots:
    void resetReturnLoginPage();

signals:
    void display(int);
    void sendMessage(const QString&);
private:
    Ui::ResetPasswdWindow *ui;
};

#endif // RESETPASSWDWINDOW_H
