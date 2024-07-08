#include "tcpserver.h"
#include <QtNetwork/QTcpSocket>

tcpserver::tcpserver()
{

}

tcpserver::tcpserver(QObject *parent, int port):QTcpServer(parent)
{
    listen(QHostAddress::Any, port); //监听本机的IP地址和端口
}

void tcpserver::incomingConnection(int socketDescriptor)
{
    TcpSocket *tcpSocket = new TcpSocket(this);
    connect(tcpSocket, SIGNAL(updateClients(QString,int)), this, SLOT(updateClients(QString,int)));
    connect(tcpSocket, SIGNAL(disconnected(int)), this, SLOT(tcpDisconnected(int)));
    tcpSocket->setSocketDescriptor(socketDescriptor);
    tcpSocketList.append(tcpSocket); //在list末尾插入数据
}

void tcpserver::updateClients(QString message, int length)
{
    emit updateServer(message, length); //发射信号
    for(int i = 0; i < tcpSocketList.count(); i++)
    {
        QTcpSocket *temp = tcpSocketList.at(i);
        if(temp->write(message.toLatin1(), length) != length)
        {
            continue;
        }
    }
}

void tcpserver::tcpDisconnected(int descriptor)
{
    for(int i = 0; i < tcpSocketList.count(); i++)
    {
        QTcpSocket *temp = tcpSocketList.at(i);
        if(temp->socketDescriptor() == descriptor)
        {
            tcpSocketList.removeAt(i);
            return;
        }
    }
    return;
}

