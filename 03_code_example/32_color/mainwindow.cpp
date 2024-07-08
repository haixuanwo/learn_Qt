#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button = new QPushButton(this);
    button->setGeometry(QRect(200,50,80,25));
    button->setText("选择颜色");
    connect(button, SIGNAL(clicked()), this, SLOT(editText()));

    label = new QLabel(this);
    label->setGeometry(QRect(50,50,100,25));
    label->setText("我的颜色可以改变");
}


void MainWindow::editText()
{
    QColorDialog::setCustomColor(0, QRgb(0x0000FF));
    QColor color = QColorDialog::getColor(QColor(0,255,0));
    QPalette p = palette();
    p.setColor(QPalette::WindowText,QColor(color));
    label->setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}
