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
    //实例QPainter
    QPainter painter(this);

    //实例QPixmap
    QPixmap pix;

    //加载图片
    pix.load("naruto.jpg");

    //原图显示
    painter.drawPixmap(0,50,183,160,pix);

    //扭曲
    painter.shear(0.5,0); //横向扭曲

    //绘制扭曲图
    painter.drawPixmap(190,50,183,160,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
