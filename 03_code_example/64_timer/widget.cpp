#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timeCount = 0;

    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout,
        [=]()
        {
            ui->lcdNumber->display(timeCount);
            timeCount++;
        }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonStart_clicked()
{
    // 启动定时器
    // 时间间隔100ms,定时器自动触发timeout
    if (false == myTimer->isActive())
    {
        myTimer->start(100);
    }
}

void Widget::on_buttonStop_clicked()
{
    if (true == myTimer->isActive())
        myTimer->stop();
}

void Widget::on_buttonReset_clicked()
{
    timeCount = 0;
    ui->lcdNumber->display(0);
}
