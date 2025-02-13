#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createMenu();
    if (!QSystemTrayIcon::isSystemTrayAvailable())
        return;

    myTrayIcon = new QSystemTrayIcon(this);
    myTrayIcon->setIcon(QIcon(":/new/prefix1/ico"));
    // 鼠标放托盘图标上提示信息
    myTrayIcon->setToolTip("Qt托盘图标功能");

    // 设置消息
    myTrayIcon->showMessage("托盘", "托盘管理", QSystemTrayIcon::Information, 10000);
    // 托盘菜单
    myTrayIcon->setContextMenu(myMenu);
    myTrayIcon->show();
}


void MainWindow::createMenu()
{
    restoreWinAction = new QAction("恢复(&R)", this);
    quitAction = new QAction("退出(&Q)", this);

    // 恢复
    connect(restoreWinAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    // 退出
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    // 添加菜单
    myMenu->addAction(restoreWinAction);
    // 分隔符
    myMenu->addSeparator();
    myMenu->addAction(quitAction);
}


void MainWindow::showNormal()
{
    this->show();
}


// 点击最小化按钮隐藏界面
void QWidget::changeEvent(QEvent *e)
{
    if ((e->type() == QEvent::WindowStateChange) && this->isMinimized())
    {
        // QTimer::singleShot(100, this, SLOT(hide()));
        this->hide();
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}
