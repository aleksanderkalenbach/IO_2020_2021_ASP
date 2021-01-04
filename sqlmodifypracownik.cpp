#include "sqlmodifypracownik.h"
#include "ui_sqlmodifypracownik.h"
#include "tableedit_pracownik.h"

#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

sqlmodifypracownik::sqlmodifypracownik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sqlmodifypracownik)
{
    ui->setupUi(this);
}

sqlmodifypracownik::~sqlmodifypracownik()
{
    delete ui;
}

void sqlmodifypracownik::on_buttonBox_accepted()
{
    QString Imie = ui->lineImie->text();
    QString Nazwisko = ui->lineNazwisko->text();
    QString Data_urodzenia = ui->lineDataUrodzenia->text();
    QString Email = ui->lineEmail->text();
    QString Telefon = ui->lineTelefon->text();
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
        query.prepare("INSERT INTO Pracownik (Imie, Nazwisko, Data_urodzenia, Email, Telefon, Aktywny)"
                      "VALUES (?, ?, ?, ?, ?, DEFAULT)");
        query.addBindValue(Imie);
        query.addBindValue(Nazwisko);
        query.addBindValue(Data_urodzenia);
        query.addBindValue(Email);
        query.addBindValue(Telefon);
        query.exec();
        db.close();
    }
}
