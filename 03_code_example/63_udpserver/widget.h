#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();    

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;

private slots:
    void dealMsg(); // 处理对方发过来的数据
    void on_buttonSend_clicked();
    void on_pushButtonBind_clicked();
};

#endif // WIDGET_H
