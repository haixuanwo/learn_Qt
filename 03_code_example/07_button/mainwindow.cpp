#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonStatus = true;

    button = new QPushButton("按钮A", this);

    // 定义按钮X轴，Y轴，W宽，H高
    button->setGeometry(QRect(100,100,100,25));

    // 给按钮添加插槽事件
    connect(button, SIGNAL(released()), this, SLOT(txtbutton()));
}


void MainWindow::txtbutton()
{
    // 改变按钮文字
    if(buttonStatus)
    {
        buttonStatus = false;
        button->setText("按钮B");
    }
    else
    {
        buttonStatus = true;
        button->setText("按钮A");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
