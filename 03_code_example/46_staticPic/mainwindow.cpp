#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::paintEvent(QPaintEvent *)
{
    //实例QPixmap
    QPixmap image("naruto.jpg");

    //实例QPainter绘制类
    QPainter painter(this);

    //绘制图片
    painter.drawPixmap(20,20,200,257,image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
