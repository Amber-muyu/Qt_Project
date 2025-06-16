#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();

signals:
    void signalMin();
    void signalIsMax();
    void signalClose();

private:
    Ui::TitleBar *ui;
};

#endif // TITLEBAR_H
