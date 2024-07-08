#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileMenu = new QMenu(this);
    editMenu = new QMenu(this);
    helpMenu = new QMenu(this);

    // 填充菜单子节点
    newAct = new QAction(QIcon(":/images/new"), tr("新建"), this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip("新建文件");
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    cutAct = new QAction(QIcon(":/images/cut"), tr("剪切"), this);
    cutAct->setShortcut(tr("Ctrl+X"));
    cutAct->setStatusTip("剪切内容");

    copyAct = new QAction(QIcon(":/images/copy"), tr("复制"), this);
    copyAct->setShortcut(tr("Ctrl+C"));
    copyAct->setStatusTip("复制内容");

    pasteAct = new QAction(QIcon(":/images/paste"), tr("粘贴"), this);
    pasteAct->setShortcut(tr("Ctrl+V"));
    pasteAct->setStatusTip("粘贴内容");

    aboutQtAct = new QAction(QIcon(":/images/paste"), tr("粘贴"), this);
    aboutQtAct->setStatusTip(tr("关于Qt信息"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    // 填充菜单
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addSeparator();

    editMenu = menuBar()->addMenu(tr("编辑"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(aboutQtAct);

    // toolBar工具条
    fileToolBar = addToolBar(tr("新建"));
    fileToolBar->addAction(newAct);

    editToolBar = addToolBar(tr("修改"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}

void MainWindow::newFile()
{
    QMessageBox::warning(this, tr("Warning"), tr("创建新文件？"),
        QMessageBox::Yes | QMessageBox::Default, QMessageBox::No);
}

MainWindow::~MainWindow()
{
    delete ui;
}
