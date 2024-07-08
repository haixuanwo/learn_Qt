#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    radioM = new QRadioButton(this);
    radioW = new QRadioButton(this);
    label  = new QLabel(this);

    // 位置宽高
    radioM->setGeometry(QRect(50,50,50,50));
    radioW->setGeometry(QRect(100,50,50,50));
    label->setGeometry(QRect(50,100,100,25));
    radioM->setText("男");
    radioW->setText("女");

    // 默认选择
    radioM->setChecked(true);
    label->setText("男");

    // 事件
    connect(radioM, SIGNAL(clicked()), this, SLOT(radioChange()));
    connect(radioW, SIGNAL(clicked()), this, SLOT(radioChange()));
}


// Radio点击方法
void MainWindow::radioChange()
{
    if (sender() == radioM)
    {
        label->setText("男");
    }
    else if (sender() == radioW)
    {
        label->setText("女");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
