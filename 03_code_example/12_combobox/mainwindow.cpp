#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    comboBox = new QComboBox(this);
    comboBox->setGeometry(QRect(50, 50, 120, 25));

    QStringList str;
    str << "数学" << "语文" << "地理";

    comboBox->addItems(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
