#include "zajeciapanel.h"
#include "ui_zajeciapanel.h"

zajeciapanel::zajeciapanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zajeciapanel)
{
    ui->setupUi(this);
}

zajeciapanel::~zajeciapanel()
{
    delete ui;
}
