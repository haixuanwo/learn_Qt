#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    edit = new QLineEdit(this);
    edit->setGeometry(QRect(50,50,200,25));
    edit->setText("shit.txt");

    content = new QLineEdit(this);
    content->setGeometry(QRect(50,100,200,25));
    content->setText("写入文件的内容");

    button = new QPushButton(this);
    button->setGeometry(QRect(270,50,80,25));
    button->setText("创建");
    connect(button, SIGNAL(clicked()), this, SLOT(createFile()));
}


void MainWindow::createFile()
{
    QFile file(edit->text());
    if (file.exists())
    {
        QMessageBox::warning(this, "创建文件", "文件已经存在！");
    }
    else
    {
        file.open(QIODevice::ReadWrite|QIODevice::Text);
        QByteArray str = content->text().toUtf8();
        file.write(str);
        QMessageBox::warning(this, "创建文件", "文件成功！");
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
