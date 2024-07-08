#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bar = new QProgressBar(this);
    bar->setGeometry(QRect(50,50,200,20));
    bar->setRange(0, 100000 - 1);
    bar->setValue(0);

    button = new QPushButton(this);
    button->setGeometry(QRect(270,50,80,25));
    button->setText("开始");
    connect(button, SIGNAL(clicked()), this, SLOT(startBar()));
}


void MainWindow::startBar()
{
    for (int i = 0; i < 100000; i++)
    {
        // 100%结束
        if (99999 == i)
        {
            button->setText("结束");
        }
        bar->setValue(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
