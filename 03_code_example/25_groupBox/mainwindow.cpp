#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    box = new QGroupBox(this);
    box->setGeometry(QRect(30,30,340,100));
    box->setTitle("语音栏目");

    button = new QPushButton();
    button->setText("按钮");

    buttonShit = new QPushButton();
    buttonShit->setText("shit");

    vbox = new QVBoxLayout;
    vbox->addWidget(button);
    vbox->addWidget(buttonShit);

    box->setLayout(vbox);
}

MainWindow::~MainWindow()
{
    delete ui;
}
