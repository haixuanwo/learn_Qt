#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    label = new QLabel(this);
    label->setGeometry(QRect(50,50,40,25));
    label->setText("网址：");

    //实例QLineEdit
    edit = new QLineEdit(this);
    edit->setGeometry(QRect(100,50,150,25));
    edit->setText("www.baidu.com");

    //实例QPushButton
    button = new QPushButton(this);
    button->setGeometry(QRect(260,50,80,25));
    button->setText("查询");
    connect(button,SIGNAL(clicked()),this,SLOT(sendUrl()));

    //实例QLabel
    result = new QLabel(this);
    result->setGeometry(QRect(50,90,150,25));
}


void MainWindow::sendUrl()
{
    QHostInfo::lookupHost(edit->text(),this,SLOT(lookedUp(QHostInfo)));
}


void MainWindow::lookedUp(const QHostInfo &host)
{
    result->setText("IP地址："+host.addresses().first().toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
