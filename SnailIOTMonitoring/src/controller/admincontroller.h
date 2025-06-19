#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTime>
#include "../database/usermanager.h"
#include "../add/adminuserinfoadd.h"
#include "../modify/adminuserinfomodify.h"

namespace Ui {
class AdminController;
}

class AdminController : public QWidget
{
    Q_OBJECT

public:
    explicit AdminController(QWidget *parent = nullptr);
    ~AdminController();
    void initUserInfoPage(const QList<QVariantMap>& users);
    void autoRefresh();

public slots:
    void addUser();
    void modifyUser();
    void deleteUser();

signals:
    void sendModifyUserInfo(int);

private:
    Ui::AdminController *ui;
    QStandardItemModel* m_model = nullptr;
    AdminUserInfoAdd* m_adminUserInfoAdd;
    AdminUserInfoModify* m_adminUserInfoModify;
    bool m_isSearching;
};

#endif // ADMINCONTROLLER_H
