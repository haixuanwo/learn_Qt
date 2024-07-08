#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //实例QLabel
    label = new QLabel(this);
    label->setGeometry(QRect(50,50,200,25));
    label->setText("按Q键更改文字");
}


//键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //键值如果等于Q
    /*if(event->key()==Qt::Key_Q)
    {
        label->setText("你按了 Q 键");
    }*/

    switch(event->key())
    {
        case Qt::Key_Q:
            label->setText("你按了 Q 键");
            break;
        case Qt::Key_W:
            label->setText("你按了 W 键");
            break;
        case Qt::Key_E:
            label->setText("你按了 E 键");
            break;
        case Qt::Key_R:
            label->setText("你按了 R 键");
            break;
        default:
            label->setText("请按 Q、W、E、R 键");
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
