#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QList>
#include "datamanage.h"

class UserManage : public QObject
{
    Q_OBJECT
public:
    explicit UserManage(QObject *parent = nullptr);

    // 用户操作
    bool addUser(const QVariantMap &userData);
    bool authenticate(const QString &username, const QString &password);
    bool updateUser(int userId, const QVariantMap &updateData);
    bool deleteUser(int userId);
    QVariantMap getUser(int userId);
    QVariantMap getUserByUsername(const QString &username);
    QList<QVariantMap> getAllUsers();
    bool changePassword(int userId, const QString &newPassword);
    bool resetPassword(const QString& msg);
    bool isUsernameExist(const QString &username);
    bool isEmailExist(const QString &email);
    bool isPhoneExist(const QString &phone);
    // 权限管理
    bool setUserRole(int userId, const QString &role);
    QString getUserRole(int userId);

signals:
    void userAdded(int userId);
    void userUpdated(int userId);
    void userDeleted(int userId);
    void authenticationFailed(const QString &username);
    void passwordChanged(int userId);

private:
    DataManage &m_dbManager;
    QSqlDatabase m_db;
    QString hashPassword(const QString &password);
    bool validateUserData(const QVariantMap &userData);
};

#endif // USERMANAGE_H
