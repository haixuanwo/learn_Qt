#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ini文件路径Label
    filePathL = new QLabel;
    filePathL->setText("ini文件完整路径");

    //ini文件路径输入框
    filePath = new QLineEdit;
    filePath->setText("001.ini");

    //节点Label
    nodeL = new QLabel;
    nodeL->setText("节点名");

    //节点输入框
    nodeEdit = new QLineEdit;
    nodeEdit->setText("node");

    //键Label
    keyL = new QLabel;
    keyL->setText("键值");

    //键输入框
    keyEdit = new QLineEdit;
    keyEdit->setText("ip");

    //值Label
    valL = new QLabel;
    valL->setText("值");

    //值输入框
    valEdit = new QLineEdit;
    valEdit->setText("192.168.1.1");

    //按钮
    writeBt = new QPushButton;
    writeBt->setText("写入文件");
    connect(writeBt,SIGNAL(clicked()),this,SLOT(writeFile()));
    gLayout = new QGridLayout;

    gLayout->addWidget(filePathL,0,0,1,1);
    gLayout->addWidget(filePath,0,1,1,4);
    gLayout->addWidget(nodeL,1,0,1,1);
    gLayout->addWidget(nodeEdit,1,1,1,1);
    gLayout->addWidget(keyL,2,0,1,1);
    gLayout->addWidget(keyEdit,2,1,1,1);
    gLayout->addWidget(valL,2,3,1,1);
    gLayout->addWidget(valEdit,2,4,1,1);
    gLayout->addWidget(writeBt,3,4,1,1);

    //实例QWidget
    widget = new QWidget();

    //绑定布局
    widget->setLayout(gLayout);
    this->setCentralWidget(widget);
}


//写入文件
void MainWindow::writeFile()
{
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件
    writeIni = new QSettings(filePath->text(), QSettings::IniFormat);

    //写入键、值
    writeIni->setValue(nodeEdit->text()+"/"+keyEdit->text(),valEdit->text());

    //写入完成删除指针
    delete writeIni;
}

MainWindow::~MainWindow()
{
    delete ui;
}
