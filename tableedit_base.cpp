#include "tableedit_base.h"
#include "ui_tableedit_base.h"

tableedit_base::tableedit_base(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableedit_base)
{
    ui->setupUi(this);
}

tableedit_base::~tableedit_base()
{
    delete ui;
}
