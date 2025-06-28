#ifndef PASSWORDMODIFY_H
#define PASSWORDMODIFY_H

#include <QWidget>
#include "../database/usermanager.h"
#include "../database/systemlogsmanager.h"

namespace Ui {
class PasswordModify;
}

class PasswordModify : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordModify(QWidget *parent = nullptr);
    ~PasswordModify();

public slots:
    void modifyPassWordByUserName(const QString&);
    void modifyUserPassword();

private:
    Ui::PasswordModify *ui;
};

#endif // PASSWORDMODIFY_H
