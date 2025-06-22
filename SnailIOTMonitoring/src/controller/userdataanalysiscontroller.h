#ifndef USERDATAANALYSISCONTROLLER_H
#define USERDATAANALYSISCONTROLLER_H

#include <QWidget>

namespace Ui {
class UserDataAnalysisController;
}

class UserDataAnalysisController : public QWidget
{
    Q_OBJECT

public:
    explicit UserDataAnalysisController(QWidget *parent = nullptr);
    ~UserDataAnalysisController();

private:
    Ui::UserDataAnalysisController *ui;
};

#endif // USERDATAANALYSISCONTROLLER_H
