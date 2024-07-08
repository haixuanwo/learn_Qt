#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    QLabel *label = new QLabel(this);

    //QLabel位置
    label->setGeometry(QRect(50,50,200,25));

    //实例QDesktopWidget
    QDesktopWidget *desktopWidget = QApplication::desktop();

    //实例QRect接收屏幕信息
    QRect screenRect = desktopWidget->screenGeometry();

    //定义字符串
    QString str = "屏幕分辨率为：";

    //屏幕宽度
    int sWidth = screenRect.width();

    //屏幕高度
    int sHeight = screenRect.height();

    //输出结果
    label->setText(str + QString::number(sWidth,10) + "X" + QString::number(sHeight,10));
}

MainWindow::~MainWindow()
{
    delete ui;
}
