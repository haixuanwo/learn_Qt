#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("客户端");

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, &QTcpSocket::connected,
        [=]()
        {
            ui->textEditRead->setText("成功和服务器建立连接");
        }
        );

    connect(tcpSocket, &QTcpSocket::readyRead,
        [=]()
        {
            QByteArray array = tcpSocket->readAll();
            ui->textEditRead->append(array);
        }
        );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ButtonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    // 主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void Widget::on_ButtonSend_clicked()
{
    // 获取编辑框内容
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void Widget::on_ButtonClose_clicked()
{
    // 主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
