#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent):QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(dataReceived())); //准备接收
    connect(this, SIGNAL(disconnected()), this, SLOT(datadisconnected())); //断开连接信号
}

void TcpSocket::dataReceived()
{
    while(this->bytesAvailable() > 0) //检查字节数
    {
        char buf[1024];
        int length = bytesAvailable();
        qDebug()<<"recv len"<<length;
        this->read(buf, length); //读取接收
        QString message = buf;
        emit updateClients(message, length); //发射信号
        qDebug()<<"len:"<<length;
    }
}

void TcpSocket::datadisconnected()
{
    emit disconnected(this->socketDescriptor());
}

