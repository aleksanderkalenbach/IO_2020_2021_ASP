#include "pracownikpanel.h"
#include "ui_pracownikpanel.h"

pracownikpanel::pracownikpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pracownikpanel)
{
    ui->setupUi(this);
}

pracownikpanel::~pracownikpanel()
{
    delete ui;
}
