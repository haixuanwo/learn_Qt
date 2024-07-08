#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "tcpsocket.h"
#include <QtNetwork>

class tcpserver:public QTcpServer
{
    Q_OBJECT
public:
    tcpserver();

    explicit tcpserver(QObject *parent = 0, int port = 0);
    QList<TcpSocket*> tcpSocketList;

protected:
    void incomingConnection(int socketDescriptor);

signals:
    void updateServer(QString, int);

public slots:
    void updateClients(QString,int);
    void tcpDisconnected(int);
};

#endif // TCPSERVER_H
