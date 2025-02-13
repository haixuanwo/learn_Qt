#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timeEdit = new QTimeEdit(this);
    timeEdit->setGeometry(QRect(50,50,120,25));

    QDateTime sysTime = QDateTime::currentDateTime();
    // 获取时分秒以“:”号拆分赋予list数组
    QStringList list = sysTime.toString("hh:mm:ss").split(':');
    // 将时分秒绑定控件
    timeEdit->setTime(QTime(list[0].toInt(), list[1].toInt(), list[2].toInt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
