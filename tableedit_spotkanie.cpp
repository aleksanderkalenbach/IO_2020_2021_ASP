#include "tableedit_spotkanie.h"
#include "ui_tableedit_spotkanie.h"
#include "sqlmodifyspotkanie.h"

#include <QtSql>
#include <QtDebug>

tableedit_spotkanie::tableedit_spotkanie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableedit_spotkanie)
{
    ui->setupUi(this);
}

tableedit_spotkanie::~tableedit_spotkanie()
{
    delete ui;
}




void tableedit_spotkanie::setValue(int row, QString id, QString data, QString grupa)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(id));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(data));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(grupa));

}

void tableedit_spotkanie::on_pushButton_dodaj_clicked()
{
    sqlmodifyspotkanie sqlmodify;
    sqlmodify.setModal(true);
    sqlmodify.exec();
}

void tableedit_spotkanie::on_pushButton_usun_clicked()
{
    int wiersz = ui->tableWidget->currentRow();
    int id = ui->tableWidget->model()->index(wiersz,0).data().toInt();
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
        query.prepare("update [Spotkanie] set Aktywny = '0' where ID_Spotkania  = :id");
        query.bindValue(0, id);
        if(query.exec())
        {
            qDebug() << "deleted";
        }
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}

void tableedit_spotkanie::on_pushButton_zmien_clicked()
{
    int wiersz = ui->tableWidget->currentRow();
    int id = ui->tableWidget->model()->index(wiersz,0).data().toInt();

    QDateTime Data = ui->tableWidget->model()->index(wiersz,1).data().toDateTime();
    QString Kurs = ui->tableWidget->model()->index(wiersz,2).data().toString();



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
        query.prepare("UPDATE [Spotkanie] SET Data=:Data, Kurs_ID_kurs=:Kurs WHERE ID_Spotkania = :id");
        query.bindValue(":Data",Data);
        query.bindValue(":Kurs",Kurs);
        query.bindValue(":id", id);
        query.exec();
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}

void tableedit_spotkanie::on_pushButton_odswiez_clicked()
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
        if(query.exec("SELECT * FROM [Spotkanie] where Aktywny = '1' ORDER BY Data"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString(), query.value(2).toString());
                 i++;
             }
        }
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}
