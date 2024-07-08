#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edit = new QLineEdit(this);
    edit->setGeometry(QRect(50,50,200,25));
    edit->setText("fuck");

    button = new QPushButton(this);
    button->setGeometry(QRect(280,50,80,25));
    button->setText("创建");
    connect(button, SIGNAL(clicked()), this, SLOT(createFolder()));
}


void MainWindow::createFolder()
{
    QDir *folder = new QDir;
    bool exist = folder->exists(edit->text());
    if (exist)
    {
        QMessageBox::warning(this, tr("创建文件夹"), tr("文件夹已存在！"));
    }
    else
    {
        bool ok = folder->mkdir(edit->text());
        //判断是否成功
        if(ok)
        {
            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
        }
        else
        {
            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败！"));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
