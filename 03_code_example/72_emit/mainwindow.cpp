#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&F, &form::mySignal, this, &MainWindow::showSelf);
}

void MainWindow::showSelf(int num, QString name)
{
    qDebug()<<num<<name;
    F.hide();
    show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    F.show();
}
