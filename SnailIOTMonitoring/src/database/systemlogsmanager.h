#ifndef SYSTEMLOGSMANAGER_H
#define SYSTEMLOGSMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantMap>
#include <QSqlError>
#include <QSqlRecord>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "databasemanager.h"
#include "../libs/QXlsx/header/xlsxdocument.h"
#include "../libs/QXlsx/header/xlsxformat.h"
#include "../libs/QXlsx/header/xlsxcellrange.h"
#include "../libs/QXlsx/header/xlsxworksheet.h"

class SystemLogsManager : public QObject
{
    Q_OBJECT
public:
    explicit SystemLogsManager(QObject *parent = nullptr);

    static SystemLogsManager &instance();

    bool addLog(const QVariantMap &logData);
    bool deleteLog(int logId);
    bool updateLog(int logId, const QVariantMap &updateData);
    QVariantMap getLogById(int logId);
    QList<QVariantMap> getAllLogs();
    QList<QVariantMap> getLogsByType(const QString &Type);
    QList<QVariantMap> getLogsByLevel(const QString &level);
    QList<QVariantMap> searchLogs(const QString &keyword);

    bool exportToCsv (const QList<QVariantMap> &data,const QString &filePath);
    bool exportToExcel(const QList<QVariantMap> &data, const QString &filePath);

private:
    QSqlDatabase m_db;

};

#endif // SYSTEMLOGSMANAGER_H
