#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QProcess>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *comm; //dos命令输入框
    QPlainTextEdit *outEdit; //命令执行反馈框
    QPushButton *btClick; //执行按钮
    QProcess *process; //QProcess
    QString output; //接收反馈信息
    QLabel *label;

private slots:
    void clickExecution(); //点击按钮事件
    void readOutput(); //QProcess事件
};

#endif // MAINWINDOW_H
