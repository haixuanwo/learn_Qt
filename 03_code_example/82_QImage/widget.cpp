#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPainter painter;
    QImage image(400, 300, QImage::Format_ARGB32);

    painter.begin(&image);
    painter.drawImage(0, 0, QImage(":/res/heng.png"));

    // 对绘图设备前50个像素点进行操作
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            image.setPixel(QPoint(i, j), qRgb(0, 255, 0));
            // image.pixel(QPoint(i, j)); // 获取像素点
        }
    }

    painter.end();

    image.save("image.png");
}

Widget::~Widget()
{
    delete ui;
}

