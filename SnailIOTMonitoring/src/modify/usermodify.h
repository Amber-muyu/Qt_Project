#ifndef USERMODIFY_H
#define USERMODIFY_H

#include <QWidget>
#include "../database/usermanager.h"
#include "../database/systemlogsmanager.h"

namespace Ui {
class UserModify;
}

class UserModify : public QWidget
{
    Q_OBJECT

public:
    explicit UserModify(QWidget *parent = nullptr);
    ~UserModify();

public slots:
    void modifyByUserName(const QString&);
    void modifyUserInfo();

signals:
    void modifyFinish(const QString&);

private:
    Ui::UserModify *ui;
};

#endif // USERMODIFY_H
