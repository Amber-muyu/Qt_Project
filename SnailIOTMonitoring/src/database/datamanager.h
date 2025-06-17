#ifndef DATAMANAGE_H
#define DATAMANAGE_H

#include <QObject>
#include <QtSql>

class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();

    static DataManager &instance();
    bool open(const QString &dbPath = "database.db");
    bool init(const QString &schemaPath = QString()); // create tables if not exist
    QSqlDatabase db() const;

private:
    QSqlDatabase m_db;

    bool executeSqlScript(const QString &filePath);
};

#endif // DATAMANAGE_H
