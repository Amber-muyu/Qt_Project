#ifndef SYSTEMLOGUSERCONTROLLER_H
#define SYSTEMLOGUSERCONTROLLER_H

#include <QWidget>

namespace Ui {
class SystemLogUserController;
}

class SystemLogUserController : public QWidget
{
    Q_OBJECT

public:
    explicit SystemLogUserController(QWidget *parent = nullptr);
    ~SystemLogUserController();

private:
    Ui::SystemLogUserController *ui;
};

#endif // SYSTEMLOGUSERCONTROLLER_H
