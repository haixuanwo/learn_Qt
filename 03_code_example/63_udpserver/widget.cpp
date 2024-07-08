#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    //udpSocket->bind(8888);

    setWindowTitle("服务器端口：8888");

    // 当对方成功发送数据过来
    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::dealMsg);
}

void Widget::dealMsg()
{
    char buf[1024] = {0};
    QHostAddress cliAddr; // 对方地址
    quint16 port;

    // 读取对方发送的内容
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddr, &port);
    if (len > 0)
    {
        // 格式化
        QString str = QString("[%1:%2] %3")
                        .arg(cliAddr.toString())
                        .arg(port)
                        .arg(buf);

        // 给编辑区设置内容
        ui->listWidget->addItem(str);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonSend_clicked()
{
    // 先获取对方IP和端口
    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();

    // 编辑区内容
    QString str = ui->textEdit->toPlainText();

    // 给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);
    ui->listWidget->addItem(str);
}

void Widget::on_pushButtonBind_clicked()
{
    quint16 port = ui->lineEditSPort->text().toInt();
    udpSocket->bind(port);
    ui->pushButtonBind->setText("已绑定");
}
