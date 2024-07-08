#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例命令输入对话框
    comm = new QLineEdit(this);
    comm->setText("ifconfig");
    comm->setGeometry(QRect(20,20,260,25));

    //实例执行按钮
    btClick = new QPushButton(this);
    btClick->setText("执行");
    btClick->setGeometry(QRect(290,20,80,25));
    connect(btClick,SIGNAL(clicked()),this,SLOT(clickExecution()));

    //实例输出对话框
    outEdit = new QPlainTextEdit(this);
    outEdit->setGeometry(QRect(20,60,800,400));

    //实例QProcess
    process = new QProcess;
    connect(process, SIGNAL(readyRead()), this, SLOT(readOutput()));

    //dos命令查阅
    label = new QLabel(this);
    label->setGeometry(QRect(380,20,200,25));
    label->setText(tr("<a href=\"http://www.baidu.com/s?wd=dos命令大全\">命令DOS查阅</a>"));

    //开启超链接
    label->setOpenExternalLinks(true);
}


//执行DOS命令
void MainWindow::clickExecution()
{
    //定义变量接收dos命令
    QString info = comm->text();

    //执行命令
    process->start(info);

    //绑定反馈值
    outEdit->setPlainText(output);
}


//QProcess 事件
void MainWindow::readOutput()
{
    //接收反馈信息
    output +=process->readAll();

    //将返回值绑定控件
    outEdit->setPlainText(output);
}


MainWindow::~MainWindow()
{
    delete ui;
}
