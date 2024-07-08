#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    // 窗体添加样式，样式为CSS样式表
    // background-image:url添加图片
    // background-repeat:no-repeat不平铺
    this->setStyleSheet("background-image:url(:/resource/naruto.ico);background-repeat:no-repeat;");
}

MainWindow::~MainWindow()
{
    delete ui;
}
