#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QXmlStreamWriter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    explainL = new QLabel(this);
    explainL->setText("文件路径：a001.xml\r\n根节点：Root");
    explainL->setGeometry(QRect(50,50,300,100));

    //实例按钮
    createBt = new QPushButton(this);
    createBt->setText("创建XML文件");
    createBt->setGeometry(QRect(50,180,100,25));
    connect(createBt,SIGNAL(clicked()),this,SLOT(createFile()));
}


//创建文件
void MainWindow::createFile()
{
    //文件路径
    QString xmlPath = "a001.xml";
    QFile file(xmlPath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //实例QXmlStreamWriter
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        //文档头
        stream.writeStartDocument();
        //根节点
        stream.writeStartElement("Root");
        //元素、值
        stream.writeAttribute("href", "http://qt.nokia.com/");
        //节点内容
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement();
        stream.writeEndDocument();
        //关闭文件
        file.close();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
