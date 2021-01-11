#include "sqlmodifykurs.h"
#include "ui_sqlmodifykurs.h"
#include "tableedit_kursy_pracownik.h"

#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>

sqlmodifykurs::sqlmodifykurs(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::sqlmodifykurs)
{
    ui->setupUi(this);
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
        query.exec("SELECT Pracownik.Imie, Pracownik.Nazwisko FROM Pracownik join Prowadzący on Pracownik.ID_Pracownika = Prowadzący.ID_Pracownika where Pracownik.Aktywny = 1");
        while(query.next())
        {
            this->ui->comboBoxID->addItem(query.value(0).toString() + " " + query.value(1).toString());
        }

        db.close();
    }
}

sqlmodifykurs::~sqlmodifykurs()
{
    delete ui;
}

void sqlmodifykurs::on_buttonBox_accepted()
{
    QString Nazwa = ui->lineNazwa->text();
    QString Data_rozpoczecia = ui->lineDataRozpoczecia->text();
    QString Data_zakonczenia = ui->lineDataZakonczenia->text();
    QString Cena = ui->lineCena->text();
    QString Poziom = ui->linePoziom->text();
    QString Wiek = ui->lineWiek->text();
    QString Prowadzacy = ui->comboBoxID->currentText();

    QString Imie = Prowadzacy.section(' ', 0, 0);
    QString Nazwisko = Prowadzacy.section(' ', 1, 1);



    if(Nazwa.isEmpty() || Data_rozpoczecia.isEmpty() || Data_zakonczenia.isEmpty()|| Prowadzacy.isEmpty())
    {
        QMessageBox messagebox;
        messagebox.critical(0, "Błąd", "Proszę uzupełnić pola.");
        this->close();
        return;
    }


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
        query.prepare("SELECT ID_Pracownika from Pracownik where Imie = :imie and Nazwisko = :nazwisko");
        query.bindValue(0, Imie);
        query.bindValue(":nazwisko", Nazwisko);
        query.exec();

        if (query.next())
        {
            QString IDProwadzacego = query.value(0).toString();


        query.prepare("INSERT INTO Kurs (Nazwa, Data_rozpoczecia, Data_zakonczenia, Cena, Poziom_zaawansowania, Od_ilu_lat, Prowadzący_ID_Pracownika, Aktywny)"
                      "VALUES (?, ?, ?, ?, ?, ?, ?, DEFAULT)");
        query.addBindValue(Nazwa);
        query.addBindValue(Data_rozpoczecia);
        query.addBindValue(Data_zakonczenia);
        query.addBindValue(Cena);
        query.addBindValue(Poziom);
        query.addBindValue(Wiek);
        query.addBindValue(IDProwadzacego);
        query.exec();
        db.close();
        }
    }
}
