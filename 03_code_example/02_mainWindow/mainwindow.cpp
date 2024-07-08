#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("txh title");

    //窗体最大300*300
    this->setMaximumSize(600,600);

    //窗体最小300*300
    this->setMinimumSize(300,300);

    //默认窗体居中显示，如果想要更改用move或setGeometry
    this->move(100,100);

    //背景红色
    this->setStyleSheet("background:green");
}

MainWindow::~MainWindow()
{
    delete ui;
}
