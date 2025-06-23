#ifndef SYSTEMLOGADMINCONTROLLER_H
#define SYSTEMLOGADMINCONTROLLER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTimer>
#include "../database/systemlogsmanager.h"

namespace Ui {
class SystemLogAdminController;
}

class SystemLogAdminController : public QWidget
{
    Q_OBJECT

public:
    explicit SystemLogAdminController(QWidget *parent = nullptr);
    ~SystemLogAdminController();
    void initLogInfoPage(const QList<QVariantMap>& logs);
    void autoRefresh();

public slots:
    void deleteLog();
    void exportLog();

private:
    Ui::SystemLogAdminController *ui;
    bool m_isSearching;
    QStandardItemModel* m_model = nullptr;
};

#endif // SYSTEMLOGADMINCONTROLLER_H
