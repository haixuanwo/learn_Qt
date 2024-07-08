#include "widget.h"
#include "ui_widget.h"
#include <QBuffer> // 内存文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //test1();
    test2();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::test1()
{
    QBuffer memFile; // 创建内存文件
    memFile.open(QIODevice::WriteOnly);

    memFile.write("111111111111");
    memFile.write("222222222222");

    memFile.close();

    qDebug() << memFile.buffer();
}

void Widget::test2()
{
    QByteArray array;
    QBuffer memFile(&array); // 创建内存文件
    memFile.open(QIODevice::WriteOnly);

    memFile.write("111111111111");
    memFile.write("222222222222");

    memFile.close();

    qDebug() << memFile.buffer();
    qDebug() << "array" << array;

    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream<<QString("测试")<<250;
    memFile1.close();
    qDebug()<<memFile1.buffer();

    memFile1.open(QIODevice::ReadOnly);
    QDataStream in;
    in.setDevice(&memFile1);
    QString str;
    int a;
    in >> str >> a;
    memFile1.close();

    qDebug() << str.toUtf8().data()<<a;
}
