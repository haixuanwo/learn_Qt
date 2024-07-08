#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tableView = new QTableView(this);
    tableView->setGeometry(QRect(50,50,310,200));

    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem("数学"));
    model->setHorizontalHeaderItem(1, new QStandardItem("语文"));
    model->setHorizontalHeaderItem(2, new QStandardItem("英语"));

    // 行，列
    model->setItem(0, 0, new QStandardItem("数学A"));
    model->setItem(0, 1, new QStandardItem("语文A"));
    model->setItem(0, 2, new QStandardItem("英语A"));

    model->setItem(1, 0, new QStandardItem("数学B"));
    model->setItem(1, 1, new QStandardItem("语文B"));
    model->setItem(1, 2, new QStandardItem("英语B"));

    // 将数据模型绑定控件
    tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
