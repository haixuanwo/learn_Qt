#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dateEdit = new QDateEdit(this);
    dateEdit->setGeometry(QRect(50,50,120,25));

    // 获取系统时间
    QDateTime sysTime = QDateTime::currentDateTime();
    // 获取时分秒以"-"号拆分赋予list数组
    QStringList list = sysTime.toString("yyyy-MM-dd").split('-');
    // 将年月日绑定控件
    dateEdit->setDate(QDate(list[0].toInt(), list[1].toInt(), list[2].toInt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
