#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hboxLayout = new QHBoxLayout();
    button1 = new QPushButton("按钮1");
    button2 = new QPushButton("按钮2");
    button3 = new QPushButton("按钮3");

    // 向布局中添加控件
    hboxLayout->addWidget(button1);
    hboxLayout->addWidget(button2);
    hboxLayout->addWidget(button3);

    // 隔离
    hboxLayout->setSpacing(60);

    widget = new QWidget();
    widget->setLayout(hboxLayout);

    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
