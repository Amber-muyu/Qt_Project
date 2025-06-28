#include "usermanager.h"

#include <QCryptographicHash>
#include <QDebug>

UserManager::UserManager(QObject *parent)
    : QObject(parent)
    , m_dbManager(DatabaseManager::instance())
    , m_db(m_dbManager.db())
{
}

UserManager& UserManager::instance()
{
    static UserManager instance;
    return instance;
}

bool UserManager::addUser(const QVariantMap &userData)
{
    if (!validateUserData(userData)) {
        return false;
    }

    if (isUsernameExist(userData["username"].toString())) {
        qWarning() << "Username already exists:" << userData["username"].toString();
        return false;
    }

    if (isEmailExist(userData["email"].toString())) {
        qWarning() << "Email already exists:" << userData["email"].toString();
        return false;
    }

    if (isEmailExist(userData["phone"].toString())) {
        qWarning() << "phone already exists:" << userData["phone"].toString();
        return false;
    }

    QVariantMap data = userData;
    data["password"] = hashPassword(data["password"].toString());

    QSqlQuery query(m_db);
    query.prepare("INSERT INTO users (username, password, email, phone, role) "
                  "VALUES (:username, :password, :email, :phone, :role)");

    query.bindValue(":username", data["username"]);
    query.bindValue(":password", data["password"]);
    query.bindValue(":email", data["email"]);
    query.bindValue(":phone", data["phone"]);
    query.bindValue(":role", data.value("role", "user"));

    if (!query.exec()) {
        qCritical() << "Failed to add user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserManager::authenticate(const QString &username, const QString &password)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT user_id, password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qCritical() << "Authentication query failed:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        return false;
    }

    QString storedHash = query.value("password").toString();
    QString inputHash = hashPassword(password);

    if (storedHash != inputHash) {
        return false;
    }

    return true;
}

bool UserManager::updateUser(const QString& username, const QVariantMap &updateData)
{
    if (updateData.isEmpty()) {
        return false;
    }

    QStringList setClauses;
    QVariantMap params;
    params["username"] = username;

    if (updateData.contains("username") && isUsernameExist(updateData["username"].toString())) {
        qWarning() << "Username already exists:" << updateData["username"].toString();
        return false;
    }

    if (updateData.contains("email") && isEmailExist(updateData["email"].toString())) {
        qWarning() << "Email already exists:" << updateData["email"].toString();
        return false;
    }

    if (updateData.contains("phone") && isPhoneExist(updateData["phone"].toString())) {
        qWarning() << "phone already exists:" << updateData["phone"].toString();
        return false;
    }

    if (updateData.contains("role")) {
        const QString role = updateData["role"].toString();
        if (role != "admin" && role != "user") {
            qWarning() << "Invalid role, must be 'admin' or 'user'";
            return false;
        }
    }

    for (auto it = updateData.begin(); it != updateData.end(); ++it) {
        if (it.key() == "password") {
            setClauses.append("password = :password");
            params["password"] = hashPassword(it.value().toString());
        } else {
            setClauses.append(QString("%1 = :%1").arg(it.key()));
            params[it.key()] = it.value();
        }
    }

    setClauses.append("updated_at = CURRENT_TIMESTAMP");

    QString sql = QString("UPDATE users SET %1 WHERE username = :username").arg(setClauses.join(", "));

    QSqlQuery query(m_db);
    query.prepare(sql);

    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) {
        qCritical() << "Failed to update user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserManager::updateUserById(int userId, const QVariantMap &updateData)
{
    if (updateData.isEmpty()) {
        return false;
    }

    QStringList setClauses;
    QVariantMap params;
    params["user_id"] = userId;

    if (updateData.contains("username") && isUsernameExist(updateData["username"].toString())) {
        qWarning() << "Username already exists:" << updateData["username"].toString();
        return false;
    }

    if (updateData.contains("email") && isEmailExist(updateData["email"].toString())) {
        qWarning() << "Email already exists:" << updateData["email"].toString();
        return false;
    }

    if (updateData.contains("phone") && isPhoneExist(updateData["phone"].toString())) {
        qWarning() << "Phone already exists:" << updateData["phone"].toString();
        return false;
    }

    if (updateData.contains("role")) {
        QString role = updateData["role"].toString();
        if (role != "admin" && role != "user") {
            qWarning() << "Invalid role, must be 'admin' or 'user'";
            return false;
        }
    }

    for (auto it = updateData.begin(); it != updateData.end(); ++it) {
        if (it.key() == "password") {
            setClauses.append("password = :password");
            params["password"] = hashPassword(it.value().toString());
        } else {
            setClauses.append(QString("%1 = :%1").arg(it.key()));
            params[it.key()] = it.value();
        }
    }

    setClauses.append("updated_at = CURRENT_TIMESTAMP");

    QString sql = QString("UPDATE users SET %1 WHERE user_id = :user_id")
            .arg(setClauses.join(", "));

    QSqlQuery query(m_db);
    query.prepare(sql);
    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    if (!query.exec()) {
        qCritical() << "Failed to update user by ID:" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserManager::deleteUser(int userId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM users WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qCritical() << "Failed to delete user:" << query.lastError().text();
        return false;
    }

    return true;
}

QVariantMap UserManager::getUser(int userId)
{
    QVariantMap user;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM users WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    if (query.exec() && query.next()) {
        for (int i = 0; i < query.record().count(); ++i) {
            user[query.record().fieldName(i)] = query.value(i);
        }
    }

    return user;
}

QVariantMap UserManager::getUserByUsername(const QString &username)
{
    QVariantMap user;
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        for (int i = 0; i < query.record().count(); ++i) {
            user[query.record().fieldName(i)] = query.value(i);
        }
    }

    return user;
}

QList<QVariantMap> UserManager::searchUsers(const QString &keyword)
{
    QList<QVariantMap> users;

    // 模糊搜索用户名、邮箱或电话
    QSqlQuery query(m_db);
    query.prepare(R"(
                  SELECT * FROM users
                  WHERE username LIKE :kw OR email LIKE :kw OR phone LIKE :kw
                  ORDER BY username
                  )");

    QString pattern = "%" + keyword + "%";
    query.bindValue(":kw", pattern);

    if (!query.exec()) {
        qCritical() << "Search users failed:" << query.lastError().text();
        return users;
    }

    while (query.next()) {
        QVariantMap user;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            user[record.fieldName(i)] = query.value(i);
        }
        users.append(user);
    }

    return users;
}

QList<QVariantMap> UserManager::getAllUsers()
{
    QList<QVariantMap> users;
    QSqlQuery query("SELECT * FROM users ORDER BY username", m_db);

    while (query.next()) {
        QVariantMap user;
        for (int i = 0; i < query.record().count(); ++i) {
            user[query.record().fieldName(i)] = query.value(i);
        }
        users.append(user);
    }

    return users;
}

bool UserManager::changePassword(const QString &username, const QString &newPassword)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE users SET password = :password WHERE username = :username");
    query.bindValue(":password", hashPassword(newPassword));
    query.bindValue(":username", username);

    if (!query.exec()) {
        qCritical() << "Failed to change password:" << query.lastError().text();
        return false;
    }

    return true;
}

bool UserManager::resetPassword(const QString &msg)
{
    if (!isEmailExist(msg) && !isPhoneExist(msg)) {
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("UPDATE users SET password = :password WHERE email = :email OR phone = :phone");
    query.bindValue(":password", hashPassword("123456")); //改成默认密码
    query.bindValue(":email", msg);
    query.bindValue(":phone", msg);

    if (!query.exec()) {
        qCritical() << "Failed to reset password:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qWarning() << "No user found with email or phone:" << msg;
        return false;
    }

    return true;
}

bool UserManager::isUsernameExist(const QString &username)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool UserManager::isEmailExist(const QString &email)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT COUNT(*) FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool UserManager::isPhoneExist(const QString &phone)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT COUNT(*) FROM users WHERE phone = :phone");
    query.bindValue(":phone", phone);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

bool UserManager::setUserRole(int userId, const QString &role)
{
    if (role != "admin" && role != "user") {
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("UPDATE users SET role = :role WHERE user_id = :user_id");
    query.bindValue(":role", role);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qCritical() << "Failed to set user role:" << query.lastError().text();
        return false;
    }

    return true;
}

QString UserManager::getUserRole(int userId)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT role FROM users WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }

    return QString();
}

QString UserManager::hashPassword(const QString &password)
{
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

void UserManager::setUserId(int userId)
{
    if (userId <= 0) return;
    m_userId = userId;
    qDebug() << "User ID set to:" << m_userId;
}

void UserManager::clearUserId()
{
    m_userId = -1;
    qDebug() << "User ID cleared";
}

bool UserManager::validateUserData(const QVariantMap &userData)
{
    if (!userData.contains("username") || userData["username"].toString().isEmpty()) {
        qWarning() << "Username is required";
        return false;
    }

    if (!userData.contains("password") || userData["password"].toString().isEmpty()) {
        qWarning() << "Password is required";
        return false;
    }

    if (userData.contains("email") && !userData["email"].toString().isEmpty()) {
        QRegExp emailRegex(R"(\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b)", Qt::CaseInsensitive);
        if (!emailRegex.exactMatch(userData["email"].toString())) {
            qWarning() << "Invalid email format";
            return false;
        }
    }

    if (userData.contains("phone") && !userData["phone"].toString().isEmpty()) {
        QRegExp phoneRegex("^1[3-9]\\d{9}$");
        if (!phoneRegex.exactMatch(userData["phone"].toString())) {
            qWarning() << "Invalid phone number format";
            return false;
        }
    }

    if (userData.contains("role") && userData["role"].toString() != "admin"
            && userData["role"].toString() != "user") {
        qWarning() << "Invalid role, must be 'admin' or 'user'";
        return false;
    }

    return true;
}
