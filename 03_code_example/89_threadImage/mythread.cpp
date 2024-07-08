#include "mythread.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QRandomGenerator>

MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::drawImage()
{
    // 定义QImage绘图设备
    QImage image(500, 500, QImage::Format_ARGB32);

    QPainter p(&image);

    QPoint a[]
    {
        QPoint(QRandomGenerator::global()->bounded(500), QRandomGenerator::global()->bounded(500)),
        QPoint(QRandomGenerator::global()->bounded(500), QRandomGenerator::global()->bounded(500)),
        QPoint(QRandomGenerator::global()->bounded(500), QRandomGenerator::global()->bounded(500)),
        QPoint(QRandomGenerator::global()->bounded(500), QRandomGenerator::global()->bounded(500)),
        QPoint(QRandomGenerator::global()->bounded(500), QRandomGenerator::global()->bounded(500))
    };

    QPen pen;
    pen.setWidth(5);
    p.setPen(pen);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    p.setBrush(brush);

    p.drawPolygon(a, 5);

    emit updateImage(image);
}
