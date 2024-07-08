#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar> // 菜单栏
#include <QAction>
#include <QDebug>
#include <QToolBar> // 工具栏
#include <QPushButton>
#include <QStatusBar> // 状态栏
#include <QLabel>     // 标签
#include <QTextEdit>  // 文本编辑
#include <QDockWidget> // 浮动窗口

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1、菜单栏===============
    QMenuBar *mBar = new QMenuBar(this);
    // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    // 添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            [=]()
            {
                qDebug()<<"新建被按下";
            });

    pFile->addSeparator(); // 添加分割线

    QAction *pOpen = pFile->addAction("打开");
    connect(pOpen, &QAction::triggered,
            [=]()
            {
                qDebug()<<"打开被按下";
            });

    // 2、工具栏================
    QToolBar *toolBar = addToolBar("toolBar");
    // 工具栏添加快捷方式
    toolBar->addAction(pNew);
    QPushButton *b = new QPushButton(this);
    b->setText("jj");
    // 添加小控件
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=]()
            {
               b->setText("123") ;
            });


    // 3、状态栏
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    // 从左往右添加
    sBar->addWidget(new QLabel("2", this));
    // 从右往左添加
    sBar->addPermanentWidget(new QLabel("3", this));


    // 4、核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 5、浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    // 给浮动窗口添加控件
    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

