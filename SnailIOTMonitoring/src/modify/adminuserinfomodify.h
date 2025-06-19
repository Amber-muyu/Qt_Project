#ifndef ADMINUSERINFOMODIFY_H
#define ADMINUSERINFOMODIFY_H

#include <QWidget>
#include "../database/usermanager.h"

namespace Ui {
class AdminUserInfoModify;
}

class AdminUserInfoModify : public QWidget
{
    Q_OBJECT

public:
    explicit AdminUserInfoModify(QWidget *parent = nullptr);
    ~AdminUserInfoModify();

public slots:
    void modifyByUserId(int);
    void modifyUserInfo();

signals:
    void modifyFinish(const QString&);

private:
    Ui::AdminUserInfoModify *ui;
    int m_userId = -1;
};

#endif // ADMINUSERINFOMODIFY_H
