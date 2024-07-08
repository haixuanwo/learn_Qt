#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMatrix>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    label = new QLabel(this);
    label->setGeometry(QRect(160,50,75,77));

    //实例QImage
    img = new QImage;

    //QImage加载图片
    img->load("naruto.jpg");

    //label显示图片
    label->setPixmap(QPixmap::fromImage(*img));

    //实例水平操作按钮
    hBt = new QPushButton(this);

    hBt->setGeometry(QRect(50,200,80,25));
    hBt->setText("水平翻转");
    connect(hBt,SIGNAL(clicked()),this,SLOT(hShow()));

    //实例垂直操作按钮
    vBt = new QPushButton(this);
    vBt->setGeometry(QRect(160,200,80,25));
    vBt->setText("垂直操作");
    connect(vBt,SIGNAL(clicked()),this,SLOT(vShow()));

    //实例角度操作按钮 88°
    angleBt = new QPushButton(this);
    angleBt->setGeometry(QRect(270,200,80,25));
    angleBt->setText("角度操作");
    connect(angleBt,SIGNAL(clicked()),this,SLOT(angleShow()));
}


//水平操作
void MainWindow::hShow()
{
    //水平翻转
    *img = img->mirrored(true,false);

    //显示图片
    label->setPixmap(QPixmap::fromImage(*img));
}

//垂直操作
void MainWindow::vShow()
{
    //垂直翻转
    *img = img->mirrored(false,true);
    //显示图片
    label->setPixmap(QPixmap::fromImage(*img));
}

//角度操作
void MainWindow::angleShow()
{
    QMatrix matrix;
    //88度角
    matrix.rotate(88);
    *img = img->transformed(matrix);
    label->setPixmap(QPixmap::fromImage(*img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
