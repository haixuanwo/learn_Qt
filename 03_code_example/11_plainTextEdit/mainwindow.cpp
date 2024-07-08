#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plainTextEdit = new QPlainTextEdit(this);

    // 位置宽高
    plainTextEdit->setGeometry(QRect(50, 50, 200, 100));

    // 添加内容
    plainTextEdit->setPlainText("第一行");
}

MainWindow::~MainWindow()
{
    delete ui;
}
