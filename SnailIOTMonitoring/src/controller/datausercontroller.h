#ifndef DATAUSERCONTROLLER_H
#define DATAUSERCONTROLLER_H

#include <QWidget>

namespace Ui {
class DataUserController;
}

class DataUserController : public QWidget
{
    Q_OBJECT

public:
    explicit DataUserController(QWidget *parent = nullptr);
    ~DataUserController();

private:
    Ui::DataUserController *ui;
};

#endif // DATAUSERCONTROLLER_H
