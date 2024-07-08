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

    //背景色
    scene->setForegroundBrush(QColor(0, 255, 255, 127));

    //字体设置
    QFont font("黑体",60);

    //添加文字
    scene->addSimpleText("图形图像",font);

    //网格
    //scene->setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
    //实例QGraphicsView
    QGraphicsView *view = new QGraphicsView(scene);

    //显示
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
