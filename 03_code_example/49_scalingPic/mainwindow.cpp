#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    //实例放大按钮
    bigBt = new QPushButton(this);
    bigBt->setGeometry(QRect(50,200,80,25));
    bigBt->setText("放大");
    connect(bigBt,SIGNAL(clicked()),this,SLOT(bShow()));

    //实例缩小按钮
    smallBt = new QPushButton(this);
    smallBt->setGeometry(QRect(260,200,80,25));
    smallBt->setText("缩小");
    connect(smallBt,SIGNAL(clicked()),this,SLOT(sShow()));
}


//放大操作
void MainWindow::bShow()
{
    *img = img->scaled(100,100,Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(*img));
}

//缩小操作
void MainWindow::sShow()
{
    *img = img->scaled(60,60,Qt::IgnoreAspectRatio);
    label->setPixmap(QPixmap::fromImage(*img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
