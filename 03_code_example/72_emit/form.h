#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>

namespace Ui { class Form; }

class form : public QWidget
{
    Q_OBJECT
public:
    explicit form(QWidget *parent = nullptr);

signals:
    emit void mySignal(int num, QString name);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
