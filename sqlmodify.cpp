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
                      "VALUES (?, ?, ?, ?, 0, DEFAULT)");
        query.addBindValue(Imie);
        query.addBindValue(Nazwisko);
        query.addBindValue(Data_urodzenia);
        query.addBindValue(Email);
        query.exec();
        db.close();
    }


}
