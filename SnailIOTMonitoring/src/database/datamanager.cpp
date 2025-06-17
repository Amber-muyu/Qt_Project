#include "datamanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DataManager::DataManager(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

DataManager &DataManager::instance() {
    static DataManager inst;
    return inst;
}

bool DataManager::open(const QString &dbPath) {
    if (m_db.isOpen()) {
       return true;
    }

    QString actualPath = dbPath;
    if (actualPath.isEmpty()) {
        QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        QDir dir(appDataPath);
        if (!dir.exists()) dir.mkpath(".");
        actualPath = dir.filePath("database.db");
    }

    m_db.setDatabaseName(actualPath);
    if (!m_db.open()) {
        qCritical() << "DB open error:" << m_db.lastError().text();
        return false;
    }

    // 启用外键支持
    QSqlQuery pragmaQuery(m_db);
    if (!pragmaQuery.exec("PRAGMA foreign_keys = ON;")) {
        qWarning() << "Failed to enable foreign key support:" << pragmaQuery.lastError().text();
    }

    return true;
}

bool DataManager::init(const QString &schemaPath) {

    QString scriptPath = schemaPath;
    if (scriptPath.isEmpty()) {
        // 默认使用资源文件中的SQL脚本
        scriptPath = ":/resources/db_schema.sql";
    }
    return executeSqlScript(scriptPath);
}

bool DataManager::executeSqlScript(const QString &filePath)
{
    QFile scriptFile(filePath);
    if (!scriptFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Failed to open SQL script:" << scriptFile.errorString();
        return false;
    }

    QTextStream stream(&scriptFile);
    QString sqlContent = stream.readAll();
    scriptFile.close();

    // 分割SQL语句（简单按分号分割，适用于简单脚本）
    QStringList sqlStatements = sqlContent.split(';', Qt::SkipEmptyParts);

    QSqlQuery query(m_db);
    for (const QString &statement : sqlStatements) {
        QString trimmed = statement.trimmed();
        if (trimmed.isEmpty()) continue;

        if (!query.exec(trimmed)) {
            qCritical() << "Failed to execute SQL:" << trimmed
                        << "\nError:" << query.lastError().text();
            return false;
        }
    }

    return true;
}

QSqlDatabase DataManager::db() const
{
    return m_db;
}

DataManager::~DataManager(){
    if(m_db.isOpen()){
        m_db.close();
    }
}
