#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filename = new QLineEdit(this);
    filename->setGeometry(QRect(50,50,230,25));

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("浏览");
    connect(button, SIGNAL(clicked()), this, SLOT(showFiles()));
}

void MainWindow::showFiles()
{
    // 定义变量str接收QFileDialog对话框获取的文件路径
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "text file(*.txt);;C file(*.cpp);;All file(*.*)");
    // 将变量绑定QLineEdit控件
    filename->setText(str.toUtf8());
}

MainWindow::~MainWindow()
{
    delete ui;
}
