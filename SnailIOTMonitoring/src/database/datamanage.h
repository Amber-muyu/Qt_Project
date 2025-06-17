#ifndef DATAMANAGE_H
#define DATAMANAGE_H

#include <QObject>
#include <QtSql>

class DataManage : public QObject
{
    Q_OBJECT
public:
    explicit DataManage(QObject *parent = nullptr);
    ~DataManage();

    static DataManage &instance();
    bool open(const QString &dbPath = "database.db");
    bool init(const QString &schemaPath = QString()); // create tables if not exist
    QSqlDatabase db() const;

private:
    QSqlDatabase m_db;

    bool executeSqlScript(const QString &filePath);
};

#endif // DATAMANAGE_H
