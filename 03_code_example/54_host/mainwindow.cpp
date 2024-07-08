#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtNetwork/QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取计算机名称
    QString localHostName = QHostInfo::localHostName();
    qDebug() << "计算机名：" << localHostName;

    //获取IP地址
    QHostInfo info = QHostInfo::fromName(localHostName);

    //遍历地址，只获取IPV4地址
    foreach(QHostAddress address,info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug() << "ipV4地址：" << address.toString();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
