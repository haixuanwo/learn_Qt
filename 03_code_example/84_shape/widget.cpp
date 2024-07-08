#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    // 把窗口背景设置为透明
    setAttribute(Qt::WA_TranslucentBackground);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/res/heng.png"));
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - p);
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
    {
        // 右键，关闭
        close();
    }
    else if (e->button() == Qt::LeftButton)
    {
        // 求坐标差值
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
