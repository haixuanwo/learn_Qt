#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fontComboBox = new QFontComboBox(this);
    button = new QPushButton(this);
    label = new QLabel(this);

    label->setGeometry(QRect(50, 150, 300, 25));
    button->setText("按钮");
    button->move(180, 50);

    connect(button, SIGNAL(released()), this, SLOT(txtButton()));
    fontComboBox->setGeometry(QRect(50, 50, 120, 25));
}

void MainWindow::txtButton()
{
    label->setText("选择字体："+fontComboBox->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}
