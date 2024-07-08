#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPainter painter;
    QPicture picture;

    painter.begin(&picture);

    painter.drawPixmap(0, 0, 80, 80, QPixmap(":/res/heng.png"));
    painter.drawLine(50, 50, 150, 50);

    painter.end();
    picture.save("../picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
#if 0
    QPicture pic;
    pic.load(":/res/picture.png");

    QPainter painter(this);
    painter.drawPicture(0, 0, pic);
#endif
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/heng.png");

    // QPixmap -> QImage
    QImage tempImage = pixmap.toImage();
    painter.drawImage(0, 0, tempImage);

    QImage image;
    image.load(":/res/heng.png");

    // QImage -> QPxi
    QPixmap tempPixmap = QPixmap::fromImage(image);
    painter.drawPixmap(300, 0, tempPixmap);
}
