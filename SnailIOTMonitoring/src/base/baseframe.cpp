#include "baseframe.h"

#ifdef Q_OS_WIN
#include <windows.h>
#endif
#include <QMessageBox>

BaseFrame::BaseFrame(QWidget *parent) : QWidget(parent)
{

}

//event->globalPos() : 鼠标在屏幕中的绝对坐标
//frameGeometry().topLeft() : 窗口左上角在屏幕中的坐标
//差值计算:鼠标坐标 - 窗口位置 保证拖动时窗口与鼠标的相对位置不变
void BaseFrame::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton) {
#ifdef Q_OS_WIN
        ReleaseCapture();
        SendMessage(HWND(winId()),WM_SYSCOMMAND,SC_MOVE | HTCAPTION, 0);
#else
        //鼠标全局坐标与窗口（左上角）位置的固定差值
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
#endif
    }
}

void BaseFrame::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,tr("关闭窗口"),tr("你确定要关闭这个页面吗"),QMessageBox::Yes | QMessageBox::No);
    switch(reply){
        case QMessageBox::Yes :
            event->accept();
            break;
        case QMessageBox::No :
            event->ignore();
            break;
        default:
            break;
    }
}

#ifdef Q_OS_WIN
#else
void BaseFrame::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() | Qt::LeftButton) {
        //新位置 = 当前光标位置 - 固定差值
        move(event->globalPos() - m_dragPosition);
    }
}
#endif
