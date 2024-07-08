#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QXmlStreamReader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    resultL = new QLabel(this);
    resultL->setGeometry(QRect(50,50,300,100));

    //实例按钮
    readBt = new QPushButton(this);
    readBt->setText("读取 title 节点");
    readBt->setGeometry(QRect(50,180,150,25));
    connect(readBt,SIGNAL(clicked()),this,SLOT(readNode()));
}


//读取节点
void MainWindow::readNode()
{
    //文件路径
    QString xmlPath = "001.xml";
    QFile file(xmlPath);
    //定义变量接收信息
    QString str;
    //判断文件是否存在
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //实例QXmlStreamReader对象读取文件
            QXmlStreamReader xmlRead(&file);

            //循环节点
            while (!xmlRead.atEnd())
            {
                //指针下移
                xmlRead.readNext();
                if(xmlRead.isStartElement())
                {
                    //如果节点有等于title的
                    if(xmlRead.name() == "title")
                    {
                        //取title值赋予变量str
                        str = xmlRead.readElementText();
                    }
                    else
                    {
                        str = "没找到节点";
                    }
                }
            }
            //将值绑定QLabel控件显示
            resultL->setText(str);
        }
        else
        {
            resultL->setText("文件打开失败");
        }
        //关闭文件
        file.close();
    }else
    {
        resultL->setText("文件不存在");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
