#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include "../database/usermanager.h"

namespace Ui {
class AdminController;
}

class AdminController : public QWidget
{
    Q_OBJECT

public:
    explicit AdminController(QWidget *parent = nullptr);
    ~AdminController();

public slots:
    void deleteUser();

private:
    Ui::AdminController *ui;
    QStandardItemModel* m_model;
};

#endif // ADMINCONTROLLER_H
