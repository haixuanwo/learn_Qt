#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 标题名
    this->setWindowTitle("移动无边框窗体");

    // 去掉标题栏
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //去掉最大化、最小化按钮，保留关闭按钮
    this->setWindowFlags(Qt::WindowCloseButtonHint);

    // 实例一个按钮控件，因为去掉标题栏后，窗体没有关闭按钮了
    // 所以自己添加一个按钮实现关闭功能
    btClose = new QPushButton(this);
    btClose->setText("关闭");

    // 按钮点击事件
    connect(btClose, SIGNAL(clicked()), this, SLOT(close()));
}


// 获取鼠标点定位窗体位置
void MainWindow::mousePressEvent(QMouseEvent * e)
{
    last = e->globalPos();
}


// 鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    move(x() + dx, y() + dy);
}


// 鼠标释放
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    move(x() + dx, y() + dy);
}


MainWindow::~MainWindow()
{
    delete ui;
}

