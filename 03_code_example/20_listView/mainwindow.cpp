#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listView = new QListView(this);
    listView->setGeometry(QRect(50,50,100,100));

    QStringList string;
    string << "数学" << "语文" << "英语" << "地理";
    model = new QStringListModel(string);

    // 将数据绑定listView控件
    listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
