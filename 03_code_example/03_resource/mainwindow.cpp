#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("Qt5.1窗体应用");

    //窗体ICO图片，如图不起别名，后缀直接写图片全名。
    this->setWindowIcon(QIcon(":/resource/bitbug_favicon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
