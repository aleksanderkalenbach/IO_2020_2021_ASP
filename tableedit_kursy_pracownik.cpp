#include "tableedit_kursy_pracownik.h"
#include "ui_tableedit_kursy_pracownik.h"
#include "sqlmodifykurs.h"

#include <QtSql>
#include <QtDebug>

tableedit_kursy_pracownik::tableedit_kursy_pracownik(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableedit_kursy_pracownik)
{
    ui->setupUi(this);
}

tableedit_kursy_pracownik::~tableedit_kursy_pracownik()
{
    delete ui;
}

void tableedit_kursy_pracownik::setValue(int row, QString id, QString nazwa, QString data_rozpoczecia, QString data_zakonczenia, QString cena, QString poziom, QString wiek)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(id));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(nazwa));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(data_rozpoczecia));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(data_zakonczenia));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(cena));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(poziom));
    ui->tableWidget->setItem(row,6,new QTableWidgetItem(wiek));

}

void tableedit_kursy_pracownik::on_pushButton_dodaj_clicked()
{
    sqlmodifykurs sqlmodify;
    sqlmodify.setModal(true);
    sqlmodify.exec();
}

void tableedit_kursy_pracownik::on_pushButton_usun_clicked()
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
        query.prepare("update [Kurs] set Aktywny = '0' where ID_kurs  = :id");
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

void tableedit_kursy_pracownik::on_pushButton_zmien_clicked()
{
    int wiersz = ui->tableWidget->currentRow();
    int id = ui->tableWidget->model()->index(wiersz,0).data().toInt();

    QString Nazwa = ui->tableWidget->model()->index(wiersz,1).data().toString();
    QDateTime Data_rozpoczecia = ui->tableWidget->model()->index(wiersz,2).data().toDateTime();
    QDateTime Data_zakonczenia = ui->tableWidget->model()->index(wiersz,3).data().toDateTime();
    QString Cena = ui->tableWidget->model()->index(wiersz,4).data().toString();
    QString Poziom = ui->tableWidget->model()->index(wiersz,5).data().toString();
    QString Wiek = ui->tableWidget->model()->index(wiersz,6).data().toString();


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
        query.prepare("UPDATE [Kurs] SET Nazwa=:Nazwa, Data_rozpoczecia=:Data_rozpoczecia, Data_zakonczenia=:Data_zakonczenia, Cena=:Cena, Poziom_zaawansowania=:Poziom, Od_ilu_lat=:Wiek WHERE ID_kurs = :id");
        query.bindValue(0,Nazwa);
        query.bindValue(":Data_rozpoczecia",Data_rozpoczecia);
        query.bindValue(":Data_zakonczenia",Data_zakonczenia);
        query.bindValue(":Cena",Cena);
        query.bindValue(":Poziom",Poziom);
        query.bindValue(":Wiek",Wiek);
        query.bindValue(":id", id);
        query.exec();
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}

void tableedit_kursy_pracownik::on_pushButton_odswiez_clicked()
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
        if(query.exec("SELECT * FROM [Kurs] where Aktywny = '1'"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString());
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
