#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap(400, 300) ;
    QPainter p(&pixmap);

    // 填充背景色
    // p.fillRect(0, 0, 400, 300, QBrush(Qt::white));
    pixmap.fill(Qt::white);

    p.drawPixmap(0, 0, 80, 80, QPixmap(":/res/heng.png"));

    // 保存图片
    pixmap.save("../pixmap.png");
}

Widget::~Widget()
{
    delete ui;
}

