#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    label->setGeometry(QRect(50,50,200,25));

    timer = new QTimer;
    //connect(timer, SIGNAL(&timerout()), this, SLOT(MainWindow::timerTime()));
    connect(timer, &QTimer::timeout,
        [=]()
        {
            QDateTime sysTime = QDateTime::currentDateTime();
            label->setText(sysTime.toString());
        }
    );

    timer->start(1000);
}


void MainWindow::timerTime()
{
    // 获取系统时间
    QDateTime sysTime = QDateTime::currentDateTime();
    label->setText(sysTime.toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}
