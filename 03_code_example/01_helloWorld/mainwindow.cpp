#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建一个QLabel控件
    QLabel *label = new QLabel(this);

    // QLabel控件显示文字内容
    label->setText("Hello world");

    // 显示位置
    label->setGeometry(QRect(50,50,200,25));
}

MainWindow::~MainWindow()
{
    delete ui;
}
