#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene;

    //QPen属性
    QPen pen;
    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(2);
    pen.setBrush(Qt::black);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    //绘制线条
    scene->addLine(30,30,200,30,pen);

    //实例QGraphicsView
    QGraphicsView *view = new QGraphicsView(scene);

    //显示
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
