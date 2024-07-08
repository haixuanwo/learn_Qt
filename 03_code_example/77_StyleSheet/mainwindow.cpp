#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ui->label->setStyleSheet("QLabel{color:red;}");

    /*ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                             "background-color:red;"
                             "}");*/

    this->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                                 "background-color:red;"
                                 "}");

//    ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
//                                 "background-color:blue;"
//                                 "border-image:url(:/res/honey.jpg)"
//                                 "}");

      // 可实现图片圆形显示
    ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                                 "min-width:128px; min-height:128px; max-width:128px; max-height:128px; border-radius:64px;"
                                 "border-image:url(:/res/honey.jpg)"
                                 "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}























