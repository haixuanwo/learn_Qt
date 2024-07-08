#include "widget.h"
#include "ui_widget.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::writeData()
{
    QFile file;
    file.setFileName("../demo.text");

    bool isOk = file.open(QIODevice::WriteOnly);
    if (true == isOk)
    {
        QTextStream stream(&file);
        // 指定编码
        stream.setEncoding(QStringConverter::Utf8);

        stream << QString("我了个去") << 250;
        file.close();
    }
}

void Widget::readData()
{
    QFile file;
    file.setFileName("../demo.text");

    bool isOk = file.open(QIODevice::ReadOnly);
    if (true == isOk)
    {
        QTextStream stream(&file);
        // 指定编码
        stream.setEncoding(QStringConverter::Utf8);

        QString str;
        int a;
        stream >> str >> a;
        cout<<str<<a;

        file.close();
    }
}

void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                    "open", "../");
    if (false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);

        bool isOk = file.open(QIODevice::ReadOnly);
        if (true == isOk)
        {
            QTextStream stream(&file);
            // 指定编码

            stream.setEncoding(QStringConverter::Utf8);
            QString str = stream.readAll();
            ui->textEdit->setText(str);

            file.close();
        }
    }
}

