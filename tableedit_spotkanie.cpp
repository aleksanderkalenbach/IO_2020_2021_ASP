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




void tableedit_spotkanie::setValue(int row, QString data, QString grupa)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(data));

    QTableWidgetItem *Grupa = new QTableWidgetItem(grupa);
    Grupa->setFlags(Grupa->flags() ^ Qt::ItemIsEditable);
    ui->tableWidget->setItem(row,1,Grupa);

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
    QDateTime Data = ui->tableWidget->model()->index(wiersz,0).data().toDateTime();
    QString Kurs = ui->tableWidget->model()->index(wiersz,1).data().toString();

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
        query.prepare("select ID_Spotkania from Spotkanie s join Kurs k on s.Kurs_ID_kurs = k.ID_kurs where s.Data = :Data and k.Nazwa = :Nazwa");
        query.bindValue(0, Data);
        query.bindValue(1, Kurs);
        query.exec();
        if(query.next())
        {
            QString id = query.value(0).toString();
            qDebug() << id;
            query.prepare("update [Spotkanie] set Aktywny = '0' where ID_Spotkania  = :id");
            query.bindValue(0, id);
            if(query.exec())
            {
                qDebug() << "deleted";
            }
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
    QString Data = ui->tableWidget->model()->index(wiersz,0).data().toString();
    QString Kurs = ui->tableWidget->model()->index(wiersz,1).data().toString();

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
        query.prepare("select ID_Spotkania from Spotkanie s join Kurs k on s.Kurs_ID_kurs = k.ID_kurs where s.Data = :Data and k.Nazwa = :Nazwa");
        query.bindValue(0, Data);
        query.bindValue(":Nazwa", Kurs);
        query.exec();
        if(query.next())
        {
            QString id = query.value(0).toString();
            query.prepare("UPDATE [Spotkanie] SET Data=:Data WHERE ID_Spotkania = :id");
            query.bindValue(":Data",Data);
            query.bindValue(":id", id);
            query.exec();
        }
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
        if(query.exec("SELECT s.Data, k.Nazwa FROM Spotkanie s join Kurs k on s.Kurs_ID_kurs = k.ID_kurs where s.Aktywny = '1' ORDER BY Data"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString());
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
