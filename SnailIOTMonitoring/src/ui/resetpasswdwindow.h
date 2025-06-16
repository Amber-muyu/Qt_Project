#ifndef RESETPASSWDWINDOW_H
#define RESETPASSWDWINDOW_H

#include <QWidget>

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

private:
    Ui::ResetPasswdWindow *ui;
};

#endif // RESETPASSWDWINDOW_H
