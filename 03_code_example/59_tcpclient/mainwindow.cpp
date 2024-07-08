#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //标题
    this->setWindowTitle("客户端");
    ui->pushButton->setDefault(true);

    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit->hide();
    ui->listWidget->hide();

    ui->label->show();
    ui->lineEdit_2->show();
    ui->pushButton_4->show();

    ui->lineEdit_2->setText("linus clark");
    ui->lineEdit_3->setText("192.168.1.4");
    ui->lineEdit_4->setText("51698");
}


void MainWindow::on_pushButton_2_clicked()
{
    QString ipAddress = ui->lineEdit_3->text(); // "192.168.1.4";
    int port = ui->lineEdit_4->text().toInt();  // 51692;

    if (ipAddress.isEmpty() || ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox::warning(this, tr("warning!!"), tr("please input IP and port!!!"));
        return;
    }

    if(!status)
    {
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket, SIGNAL(connected()), this, SLOT(tcpConnected()));
        connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(tcpDisconnected()));
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));

        tcpSocket->connectToHost(ipAddress, port);
        status = true;
    }
    else
    {
        QString message = userName + tr(":Leave Chat Room");
        tcpSocket->write(message.toLatin1(), message.length());
        tcpSocket->disconnectFromHost();
        status = false;
    }
}

void MainWindow::tcpConnected()
{
    int length = 0;
    ui->pushButton_2->setText("退出连接");
    QString message = userName + tr(":Enter Chat Room");
    length = tcpSocket->write(message.toLatin1(), message.length());

    if (length != message.length())
    {
        return;
    }
}

void MainWindow::tcpDisconnected()
{
    ui->pushButton_2->setText("连接服务");
    ui->lineEdit_2->show();
    ui->label->show();
    ui->pushButton_4->show();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit->hide();
    ui->listWidget->hide();
}

void MainWindow::dataReceived()
{
    while(tcpSocket->bytesAvailable() > 0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(), datagram.length());

        QString message = "服务端：";
        message += datagram.data();
        ui->listWidget->addItem(message);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        return;
    }

    QString message = userName + tr(":") + ui->lineEdit->text();
    tcpSocket->write(message.toLatin1(), message.length());
    ui->lineEdit->clear();

    // 发送数据显示在聊天框
    ui->listWidget->addItem(message);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this, tr("warning!!"),
        tr("please input you Name!"));
        return;
    }
    else
    {
        userName = ui->lineEdit_2->text();

        /*ui->lineEdit_2->hide();
        ui->label->hide();
        ui->pushButton_4->hide();*/

        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->lineEdit->show();
        ui->listWidget->show();
    }
}


//键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Enter:
            on_pushButton_clicked();
            qDebug()<<"run slot func";
            break;

        case Qt::Key_Return: //16777220:
            on_pushButton_clicked();
            qDebug()<<"shit ni ma bi";
            break;

        default:
            qDebug()<<"what's this:"<<event->key();
            break;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
