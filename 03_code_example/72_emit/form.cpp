#include "form.h"
#include "ui_form.h"


form::form(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
}

void form::on_pushButton_clicked()
{
    emit mySignal(100, "tanheng");
}
