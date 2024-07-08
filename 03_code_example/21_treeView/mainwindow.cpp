#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeView = new QTreeView(this);
    treeView->setGeometry(QRect(50,50,250,200));

    // 实例数据类型4个节点，2列
    model = new QStandardItemModel(3, 2);

    // 列名称
    model->setHeaderData(0, Qt::Horizontal, "第一列");
    model->setHeaderData(1, Qt::Horizontal, "第二列");

    // 定义节点
    QStandardItem *item1 = new QStandardItem("数学");
    item1->setIcon(QIcon(":/new/prefix1/folder"));

    QStandardItem *item2 = new QStandardItem("语文");
    item1->setIcon(QIcon(":/new/prefix1/folder"));

    QStandardItem *item3 = new QStandardItem("英语");
    item1->setIcon(QIcon(":/new/prefix1/folder"));

    // 英语子项
    QStandardItem *item4 = new QStandardItem("英语A");
    item4->setIcon(QIcon(":/new/prefix1/file"));
    item3->appendRow(item4);

    // 将节点添加至QStandardItemModel
    model->setItem(0, 0, item1);
    model->setItem(1, 0, item2);
    model->setItem(2, 0, item3);

    // 将QStandardItemModel数据绑定QTreeView控件
    treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
