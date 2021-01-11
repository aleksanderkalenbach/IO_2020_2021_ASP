#include "tableedit_kursy_student.h"
#include "ui_tableedit_kursy_student.h"
#include <QtSql>
#include <QtDebug>

tableedit_kursy_student::tableedit_kursy_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableedit_kursy_student)
{
    ui->setupUi(this);
}

tableedit_kursy_student::~tableedit_kursy_student()
{
    delete ui;
}

void tableedit_kursy_student::setValue(int row, QString nazwa, QString data_rozpoczecia, QString data_zakonczenia, QString cena, QString poziom, QString wiek, QString prowadzacy)
{
    ui->tableWidget_2->insertRow(row);
    ui->tableWidget_2->setItem(row,0,new QTableWidgetItem(nazwa));
    ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(data_rozpoczecia));
    ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(data_zakonczenia));
    ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(cena));
    ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(poziom));
    ui->tableWidget_2->setItem(row,5,new QTableWidgetItem(wiek));
    ui->tableWidget_2->setItem(row,6,new QTableWidgetItem(prowadzacy));


}

void tableedit_kursy_student::on_pushButton_odswiez_clicked()
{
    ui->tableWidget_2->setRowCount(0);
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
        if(query.exec("SELECT Nazwa, Data_rozpoczecia, Data_Zakonczenia, Cena, Poziom_zaawansowania, Od_ilu_lat, (Pracownik.Imie+' '+Pracownik.Nazwisko) AS Prowadzacy FROM [Kurs] join Pracownik on Kurs.Prowadzący_ID_Pracownika = Pracownik.ID_Pracownika where Kurs.Aktywny = '1'"))
        {
            int i=0;
             while(query.next())
             {
                 setValue(i, query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString());
                 i++;
             }
             ui->tableWidget_2->resizeColumnsToContents();
        }
        db.close();
    }
    else
    {
        qDebug() << "error = " << db.lastError();
    }
}
