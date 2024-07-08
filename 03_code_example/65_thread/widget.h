#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void dealTimeout();      // 定时器槽函数
    void dealDone();         // 线程结束槽函数
    void stopThread();       // 停止线程

private:
    Ui::Widget *ui;
    QTimer *myTimer;
    myThread *thread;

private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_H
