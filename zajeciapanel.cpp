#include "zajeciapanel.h"
#include "ui_zajeciapanel.h"

zajeciapanel::zajeciapanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zajeciapanel)
{
    ui->setupUi(this);
}


void zajeciapanel::on_pushButton_2_clicked()
{
    tableedit_obecnosci* t = new tableedit_obecnosci();
    t->show();
}
zajeciapanel::~zajeciapanel()
{
    delete ui;
}
