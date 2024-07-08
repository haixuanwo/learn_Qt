#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scrollBar = new QScrollBar(this);
    spinBox = new QSpinBox(this);

    scrollBar->setOrientation(Qt::Horizontal);
    scrollBar->setGeometry(QRect(50,50,180,20));
    spinBox->setGeometry(QRect(50,90,100,25));

    // 控制条宽度
    scrollBar->setPageStep(10);

    // scrollBar事件
    connect(scrollBar, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    // spinBox事件
    connect(spinBox, SIGNAL(valueChanged(int)), scrollBar, SLOT(setValue(int)));

    // 初始值
    scrollBar->setValue(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}
