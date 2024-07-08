#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTimer>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    QLabel *label = new QLabel(this);
    label->setGeometry(QRect(50,50,658,697));

    //实例QMovie
    QMovie *movie = new QMovie("naruto.jpg");

    //3秒后图片消失
    QTimer::singleShot( 30*1000, label, SLOT(close()));
    label->setMovie(movie);
    movie->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
