#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel("我是QLabel", this);

    // QLabel位置
    // label->move(100, 100);
    label->setGeometry(QRect(100,100,200,30));

    // label样式（CSS样式表）
    // font-size字号
    // color 字体颜色
    // font-weight字宽
    // font-style 字体样式
    label->setStyleSheet("font-size:20px;color:red;font-weight:bold;font-style:italic");
}

MainWindow::~MainWindow()
{
    delete ui;
}
