#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *);
    void getImage(QImage);
    void dealClose(); // 窗口关闭
private:
    Ui::Widget *ui;
    MyThread *myT;
    QThread *thread;
    QImage image;
};
#endif // WIDGET_H
