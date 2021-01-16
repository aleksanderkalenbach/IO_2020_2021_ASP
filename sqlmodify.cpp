#include "sqlmodify.h"
#include "ui_sqlmodify.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include "tableedit_base.h"
#include <QMessageBox>

SqlModify::SqlModify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SqlModify)
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
        query.exec("SELECT Kurs.Nazwa FROM Kurs  WHERE Kurs.Aktywny=1");
        while(query.next())
        {
            this->ui->comboNazwa->addItem(query.value(0).toString());
        }

        db.close();
    }
}

SqlModify::~SqlModify()
{
    delete ui;
}

void SqlModify::on_buttonBox_accepted()
{


    QString Imie = ui->lineImie->text();
    QString Nazwisko = ui->lineNazwisko->text();
    QString Data_urodzenia = ui->lineDataUrodzenia->text();
    QString Email = ui->lineEmail->text();
    QString Uczestnik_kurs = ui->comboNazwa->currentText();


    if(Imie.isEmpty() || Nazwisko.isEmpty() || Data_urodzenia.isEmpty())
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
        query.prepare("INSERT INTO Uczestnik (Imie, Nazwisko, Data_urodzenia, Email, Kwota_do_zaplaty, Aktywny)"
                      "VALUES (?, ?, ?, ?, 0, DEFAULT);");
        query.addBindValue(Imie);
        query.addBindValue(Nazwisko);
        query.addBindValue(Data_urodzenia);
        query.addBindValue(Email);
        query.exec();
        query.next();
        query.prepare("SELECT ID_kurs, Cena from Kurs where Nazwa = :Nazwa;");
        query.bindValue(0, Uczestnik_kurs);
        query.exec();
        query.next();
        QString Kurs_ID = query.value(0).toString();
        QString Cena = query.value(1).toString();
        query.prepare("SELECT ID_Uczestnicy FROM Uczestnik WHERE Imie = :Imie and Nazwisko = :Nazwisko;");
        query.bindValue(0, Imie);
        query.bindValue(1, Nazwisko);
        query.exec();
        query.next();
        QString Uczestnik_ID = query.value(0).toString();
        query.prepare("update Uczestnik set Kwota_do_zaplaty = Kwota_do_zaplaty + :Cena where ID_Uczestnicy = :Uczestnik_ID;");
        query.bindValue(0, Cena);
        query.bindValue(1, Uczestnik_ID);
        query.exec();
        query.prepare("SET IDENTITY_INSERT Uczestnik_kurs ON;"
                      "INSERT INTO Uczestnik_kurs (Kurs_ID_kurs, Uczestnik_ID_Uczestnicy) VALUES (?, ?);"
                      "SET IDENTITY_INSERT Uczestnik_kurs OFF;");
        query.addBindValue(Kurs_ID);
        query.addBindValue(Uczestnik_ID);
        query.exec();
        db.close();



    }


}
