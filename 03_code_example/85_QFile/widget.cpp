#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                    "open", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        // 文件对象
        QFile file(path);
        bool isOk = file.open(QIODevice::ReadOnly);
        if (isOk == true)
        {
#if 0
            // 读文件，默认只识别utf-8编码
            QByteArray array = file.readAll();
            ui->textEdit->setText(array);
#endif
            QByteArray array;
            while(file.atEnd() == false)
            {
                array += file.readLine();
            }
            ui->textEdit->setText(array);
        }
        file.close();

        // 获取文件信息
        QFileInfo info(path);
        qDebug()<<"文件名字："<<info.fileName();
        qDebug()<<"文件后缀："<<info.suffix();
        qDebug()<<"文件大小："<<info.size();
        qDebug()<<"文件创建时间："<<info.birthTime().toString("yyyy-MM-dd hh:mm:ss");
    }
}


void Widget::on_pushButtonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save",
                                  "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        QFile file;
        file.setFileName(path);

        // 打开文件，只写方式
        bool isOk = file.open(QIODevice::WriteOnly);
        if (isOk == true)
        {
            // 获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            // 写文件
            // QString -> QByteArray
            // file.write(str.toUtf8());

            // QString -> c++ string -> char*
            file.write(str.toStdString().data());
            // 转换为本地平台编码
            // file.write(str.toLocal8Bit());

            // QString -> QByteArray
            QString buf = "123";
            QByteArray a = buf.toUtf8(); // 中文
            a = buf.toLocal8Bit(); // 本地编码

            // QByteArray -> char *
            char *b = a.data();

            // char* -> QString
            char* p = "abc";
            QString c = QString(p);
        }
        file.close();
    }
}
