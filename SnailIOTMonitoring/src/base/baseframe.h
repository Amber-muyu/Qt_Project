#ifndef BASEFRAME_H
#define BASEFRAME_H

#include <QWidget>
#include <QMouseEvent>

class BaseFrame : public QWidget
{
    Q_OBJECT
public:
    explicit BaseFrame(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

#ifdef Q_OS_WIN
#else
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint m_dragPosition;
#endif
};

#endif // BASEFRAME_H
