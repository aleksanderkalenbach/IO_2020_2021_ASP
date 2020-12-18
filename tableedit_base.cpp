#include "tableedit_base.h"
#include "ui_tableedit_base.h"
#include "sqlmodify.h"
#include <QtSql>
#include <QtDebug>

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

void tableedit_base::setValue(int row, QString id, QString imie, QString nazwisko, QString dataUrodzenia, QString email, QString kwotaDoZaplaty)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(id));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(imie));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(nazwisko));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(dataUrodzenia));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(email));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(kwotaDoZaplaty));
}


void tableedit_base::on_pushButton_clicked()
{
    SqlModify sqlmodify;
    sqlmodify.setModal(true);
    sqlmodify.exec();

}

void tableedit_base::on_pushButton_2_clicked()
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
        query.prepare("update [Uczestnik] set Aktywny = '0' where ID_Uczestnicy = :id");
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

void tableedit_base::on_pushButton_3_clicked()
{
    int wiersz = ui->tableWidget->currentRow();
    int id = ui->tableWidget->model()->index(wiersz,0).data().toInt();
    QString Imie = ui->tableWidget->model()->index(wiersz,1).data().toString();
    QString Nazwisko = ui->tableWidget->model()->index(wiersz,2).data().toString();
    QDateTime Data_urodzenia = ui->tableWidget->model()->index(wiersz,3).data().toDateTime();
    QString Email = ui->tableWidget->model()->index(wiersz,4).data().toString();
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
        query.prepare("UPDATE [Uczestnik] SET Imie=:Imie, Nazwisko=:Nazwisko, Data_urodzenia=:Data_urodzenia, Email=:Email WHERE ID_Uczestnicy = :id");
        query.bindValue(0,Imie);
        query.bindValue(":Nazwisko",Nazwisko);
        query.bindValue(":Data_urodzenia",Data_urodzenia);
        query.bindValue(":Email",Email);
        query.bindValue(":id", id);
        query.exec();
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}

void tableedit_base::on_pushButton_4_clicked()//funkcja odświeżenia rekordów
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
        if(query.exec("SELECT * FROM [Uczestnik] where Aktywny = '1'"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString());
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


