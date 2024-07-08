#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpserver = new QTcpServer(this);

    int port = 51690;
    tcpserver->listen(QHostAddress::Any, port);

    tcpserver->receivers()

    tcpSocket = new QTcpSocket(tcpserver);
    connect(tcpSocket, SIGNAL(tcpSocket->readyRead()), this, SLOT(dataReceived())); //准备接收
}

void MainWindow::dataReceived()
{
    int length = 0;
    char buf[1024] = {0};

    while(1) //检查字节数
    {
        length = tcpSocket->bytesAvailable();
        if (length <= 0)
            return;

        qDebug()<<"recv len"<<length;
        tcpSocket->read(buf, length);
        tcpSocket->write(buf, length);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
