#include "startpanel.h"
#include "ui_startpanel.h"

startpanel::startpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startpanel)
{
    ui->setupUi(this);
}

startpanel::~startpanel()
{
    delete ui;
}

void startpanel::on_pushButton_2_clicked()
{

}
