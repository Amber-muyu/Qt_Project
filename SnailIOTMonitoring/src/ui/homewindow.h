#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include "../utils/utils.h"

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

public slots:
    void logoutReturnPage();

signals:
    void display(int);

private:
    Ui::HomeWindow *ui;
};

#endif // HOMEWINDOW_H
