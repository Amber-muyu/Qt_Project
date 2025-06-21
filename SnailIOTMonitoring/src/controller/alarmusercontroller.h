#ifndef ALARMUSERCONTROLLER_H
#define ALARMUSERCONTROLLER_H

#include <QWidget>

namespace Ui {
class AlarmUserController;
}

class AlarmUserController : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmUserController(QWidget *parent = nullptr);
    ~AlarmUserController();

private:
    Ui::AlarmUserController *ui;
};

#endif // ALARMUSERCONTROLLER_H
