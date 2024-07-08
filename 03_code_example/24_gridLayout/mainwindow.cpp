#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gridLayout = new QGridLayout();
    button1 = new QPushButton("按钮1");
    button2 = new QPushButton("按钮2");
    button3 = new QPushButton("按钮3");

    gridLayout->addWidget(button1,0,0,1,1);
    gridLayout->addWidget(button2,0,1,1,1);
    gridLayout->addWidget(button3,1,0,1,1);

    widget = new QWidget();
    widget->setLayout(gridLayout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
