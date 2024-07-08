#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    // QPainter painter(this);

    QPainter p;
    p.begin(this); // 指定当前窗口为绘图设备

    // 绘图操作

    // 定义画笔
    QPen pen;
    pen.setWidth(5); // 设置线宽
    pen.setColor(QColor(14, 9, 234)); // RGB设置颜色
    pen.setStyle(Qt::DashLine); // 设置风格

    p.setPen(pen);

    // 画背景图
//    p.drawPixmap(0, 0, width(), height(), QPixmap(":/res/BOARD.BMP"));
    //p.drawPixmap(rect(), QPixmap(":/res/BOARD.BMP"));

    p.drawLine(50, 50, 150, 50);    // 画直线

    // 创建画刷
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::Dense1Pattern); // 设置样式
    p.setBrush(brush);

    p.drawRect(150, 150, 100, 50);  // 画矩形
    p.drawEllipse(QPoint(150, 150), 50, 25); // 画圆

    // 画笑脸
    p.drawPixmap(x, 200, 80, 80, QPixmap(":/res/heng.png"));

    p.end();
}


void Widget::on_pushButton_clicked()
{
    x += 20;
    if (x > width())
    {
        x = 0;
    }

    // 刷新窗口，让窗口重绘，整个窗口都刷新
    update(); // 间接调用painterEvent()
}
