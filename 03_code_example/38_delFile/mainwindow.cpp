#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //显示文件路径
    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50,50,200,25));

    //浏览文件按钮
    browseBt = new QPushButton(this);
    browseBt->setText("浏览文件");
    browseBt->setGeometry(QRect(270,50,80,25));
    connect(browseBt,SIGNAL(clicked()),this,SLOT(browseFile()));

    //删除文件按钮
    deleteBt = new QPushButton(this);
    deleteBt->setText("删除文件");
    deleteBt->setGeometry(QRect(50,100,80,25));
    connect(deleteBt,SIGNAL(clicked()),this,SLOT(deleteFile()));
}


//浏览文件
void MainWindow::browseFile()
{
    //定义变量str接收QFileDialog对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");

    //将变量绑定QTextEdit控件
    filePath->setText(str.toUtf8());
}

//删除文件
void MainWindow::deleteFile()
{
    //删除文件
    QFile::remove(filePath->text());
    QMessageBox::warning(this, "删除文件", "文件删除成功！");
}

MainWindow::~MainWindow()
{
    delete ui;
}
