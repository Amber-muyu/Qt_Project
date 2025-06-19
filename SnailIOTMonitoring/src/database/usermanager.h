#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QList>
#include "datamanager.h"

class UserManager : public QObject
{
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = nullptr);

    static UserManager& instance();  // 单例访问接口
    // 用户操作
    bool addUser(const QVariantMap &userData);
    bool authenticate(const QString &username, const QString &password);
    bool updateUser(const QString& username, const QVariantMap &updateData);
    bool updateUserById(int userId, const QVariantMap &updateData);
    bool deleteUser(int userId);
    QVariantMap getUser(int userId);
    QVariantMap getUserByUsername(const QString &username);
    QList<QVariantMap> searchUsers(const QString &keyword);
    QList<QVariantMap> getAllUsers();
    bool changePassword(const QString &username, const QString &newPassword);
    bool resetPassword(const QString& msg);
    bool isUsernameExist(const QString &username);
    bool isEmailExist(const QString &email);
    bool isPhoneExist(const QString &phone);
    // 权限管理
    bool setUserRole(int userId, const QString &role);
    QString getUserRole(int userId);
    QString hashPassword(const QString &password);

signals:
    void userAdded(int userId);
    void userUpdated(const QString &username);
    void userDeleted(int userId);
    void authenticationFailed(const QString &username);
    void passwordChanged(const QString &username);

private:
    DataManager &m_dbManager;
    QSqlDatabase m_db;
    bool validateUserData(const QVariantMap &userData);
};

#endif // USERMANAGE_H
