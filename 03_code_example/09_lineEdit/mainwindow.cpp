#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建QLineEdit控件
    lineEdit = new QLineEdit(this);

    // 位置大小
    lineEdit->setGeometry(QRect(100, 100, 200, 25));

    // 样式
    // border边框线大小
    // border-style边框样式 solid实线
    // border-color:blue red上下蓝色 左右红色
    lineEdit->setStyleSheet("border:lpx;border-style:solid;color:black;border-color:blue red;");

    // 限制最长输入12位
    lineEdit->setMaxLength(12);

    // 不可写入
    // lineEdit->setEchoMode(QLineEdit::NoEcho);
    // 密码*号输入
    lineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}
