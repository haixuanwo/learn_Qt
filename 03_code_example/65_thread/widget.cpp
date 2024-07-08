#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &Widget::dealTimeout);

    thread = new myThread(this);
    connect(thread, &myThread::isDone, this, &Widget::dealDone);

    // 当按窗口右上角x时触发destroy
    connect(this, &myThread::destroyed, this, &Widget::stopThread);
}

void Widget::stopThread()
{
    // 停止线程
    thread->quit();
    // 等待线程处理完手头工作
    thread->wait();
}

void Widget::dealDone()
{
    qDebug()<<"It is over";
    myTimer->stop();
}


void Widget::dealTimeout()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if (myTimer->isActive() == false)
    {
        myTimer->start(100);
    }

    // 非常复杂的函数处理，耗时较长
    //QThread::sleep(5);
    // 处理完数据后，关闭定时器
    //myTimer->stop();
    //qDebug() << "over";

    // 启动线程，处理数据
    thread->start();
}
