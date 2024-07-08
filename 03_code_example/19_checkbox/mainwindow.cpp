#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    checkBox01 = new QCheckBox(this);
    checkBox02 = new QCheckBox(this);
    checkBox03 = new QCheckBox(this);
    label      = new QLabel(this);

    checkBox01->setGeometry(QRect(50,50,50,50));
    checkBox02->setGeometry(QRect(100,50,50,50));
    checkBox03->setGeometry(QRect(150,50,50,50));
    label->setGeometry(QRect(50,100,200,30));

    checkBox01->setText("数学");
    checkBox02->setText("语文");
    checkBox03->setText("地理");

    connect(checkBox01, SIGNAL(clicked(bool)), this, SLOT(checkChannge()));
    connect(checkBox02, SIGNAL(clicked(bool)), this, SLOT(checkChannge()));
    connect(checkBox03, SIGNAL(clicked(bool)), this, SLOT(checkChannge()));
}


void MainWindow::checkChannge()
{
    if (sender() == checkBox01)
    {
        if (checkBox01->checkState() == Qt::Checked)
            str += "数学";
        else
            str = str.replace(QString("数学"), QString(""));
    }
    else if (sender() == checkBox02)
    {
        if (checkBox02->checkState() == Qt::Checked)
            str += "语文";
        else
            str = str.replace(QString("语文"), QString(""));
    }
    else if (sender() == checkBox03)
    {
        if (checkBox03->checkState() == Qt::Checked)
            str += "地理";
        else
            str = str.replace(QString("地理"), QString(""));
    }

    label->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
