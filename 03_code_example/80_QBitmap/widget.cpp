#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    // 图片背景透明
    p.drawPixmap(0, 0, QPixmap(":/res/heng.png"));
    p.drawPixmap(300, 0, QBitmap(":/res/heng.png"));

    // QPixmap 图片背景白色
    QPixmap pixmap;
    pixmap.load(":/res/heng.png");
    p.drawPixmap(0, 300, pixmap);

    // QBitmap 图片背景白色
    QBitmap bitmap;
    bitmap.load(":/res/heng.png");
    p.drawPixmap(300, 300, pixmap);
}
