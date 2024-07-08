#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spinBox = new QSpinBox(this);

    spinBox->setGeometry(QRect(50,50,100,25));
    spinBox->setRange(0, 200);
    spinBox->setValue(10);
    spinBox->setSuffix("元");
    spinBox->setPrefix("$");
}


MainWindow::~MainWindow()
{
    delete ui;
}
