#include "tableedit_obecnosci.h"
#include "ui_tableedit_obecnosci.h"
#include <QtSql>
#include <QtDebug>

tableedit_obecnosci::tableedit_obecnosci(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableedit_obecnosci)
{
    ui->setupUi(this);
}

void tableedit_obecnosci::setValue(int row, QString id, QString uczestnik, QString zajecia)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(id));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(uczestnik));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(zajecia));

}

void tableedit_obecnosci::on_pushButton_clicked()
{
        //TODO: obsługa sprawdzania obecnosci
}

void tableedit_obecnosci::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(0);
    QString servername = "LOCALHOST";
    QString dbname = "szkolaPlywacka";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;UID=test;PWD=test;").arg(servername).arg(dbname);
    db.setDatabaseName(dsn);
    if(db.open())
    {
        qDebug() << "open";
        QSqlQuery query;
        if(query.exec("SELECT * FROM [Obecnosc]"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString(), query.value(2).toString());
                 i++;
             }
             ui->tableWidget->resizeColumnsToContents();
        }
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}

tableedit_obecnosci::~tableedit_obecnosci()
{
    delete ui;
}
