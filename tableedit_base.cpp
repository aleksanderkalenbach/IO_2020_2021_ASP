#include "tableedit_base.h"
#include "ui_tableedit_base.h"
#include "sqlmodify.h"

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

void tableedit_base::setValue(int row, QString imie, QString nazwisko)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(imie));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(nazwisko));
}


void tableedit_base::on_pushButton_clicked()
{
    SqlModify sqlmodify;
    sqlmodify.setModal(true);
    sqlmodify.exec();

}

void tableedit_base::on_pushButton_2_clicked()
{


}
