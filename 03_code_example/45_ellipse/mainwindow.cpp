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

    //绘制椭圆
    scene->addEllipse(50,50,100,120);

    //实例QGraphicsView
    QGraphicsView *view = new QGraphicsView(scene);

    //显示
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
