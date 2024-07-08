#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = NULL;

    // 监听套接字，指定父对象，让其自动回收空间
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, 8888);

    setWindowTitle("服务器：8888");

    connect(tcpServer, &QTcpServer::newConnection,
        [=]()
        {
            // 取出建立好连接的套接字
            tcpSocket = tcpServer->nextPendingConnection();

            // 获取对方IP和端口
            QString ip = tcpSocket->peerAddress().toString();
            qint16 port = tcpSocket->peerPort();
            QString tmp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
            ui->textEditRead->setText(tmp);

            connect(tcpSocket, &QTcpSocket::readyRead,
                    [=]()
                    {
                        QByteArray array = tcpSocket->readAll();
                        ui->textEditRead->append(array);
                    }

                    );
        }

        );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonSend_clicked()
{
    if (NULL == tcpSocket)
        return;

    // 获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void Widget::on_ButtonClose_clicked()
{
    if (NULL == tcpSocket)
        return;

    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
