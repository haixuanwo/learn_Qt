#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //文件路径
    filePath = new QLineEdit(this);
    filePath->setGeometry(QRect(50,50,200,25));

    //浏览按钮
    browseBt = new QPushButton(this);
    browseBt->setGeometry(QRect(270,50,80,25));
    browseBt->setText("浏览");
    connect(browseBt,SIGNAL(clicked()),this,SLOT(browseFile()));

    //新名字
    newName = new QLineEdit(this);
    newName->setGeometry(QRect(50,90,200,25));
    newName->setText("新名字.txt");

    //保存按钮
    saveBt = new QPushButton(this);
    saveBt->setGeometry(QRect(270,90,80,25));
    saveBt->setText("保存");
    connect(saveBt,SIGNAL(clicked()),this,SLOT(saveFile()));
}


//浏览
void MainWindow::browseFile()
{
    //定义变量str接收QFileDialog对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this,"open file","/","text file(*.txt);;C file(*.cpp);;All file(*.*)");

    //将变量绑定QTextEdit控件
    filePath->setText(str.toUtf8());
}


//保存
void MainWindow::saveFile()
{
    //实例QFileInfo函数
    QFileInfo file(filePath->text());

    //获取文件路径
    QString path = file.absolutePath();

    //bool型变量接收是否修改成功成功true，不成功false。
    bool x = QFile::rename(filePath->text(),path + "/" + newName->text());
    if(x)
    {
        QMessageBox::warning(this,"修改文件名","文件修改成功！");
    }
    else
    {
        QMessageBox::warning(this,"修改文件名","文件修改失败！");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
