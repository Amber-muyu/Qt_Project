#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class StatusBar;
}

class StatusBar : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

public slots:
    void receiveMessage(const QString&);
    void clearMessage();

private:
    Ui::StatusBar *ui;
    QTimer* m_timer;
};

#endif // STATUSBAR_H
