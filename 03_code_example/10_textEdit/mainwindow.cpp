#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 实例QTextEdit
    textEdit = new QTextEdit(this);

    // 控件位置大小
    textEdit->setGeometry(QRect(50,50,200,150));

    // 内容
    textEdit->setText("我是第一行<br/>我是第二行");
}


MainWindow::~MainWindow()
{
    delete ui;
}
