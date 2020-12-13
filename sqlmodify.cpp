#include "sqlmodify.h"
#include "ui_sqlmodify.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include "tableedit_base.h"

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
        query.prepare("INSERT INTO Studenci (Imie, Nazwisko)"
                      "VALUES (?, ?)");
        query.addBindValue(Imie);
        query.addBindValue(Nazwisko);
        query.exec();
        db.close();
    }


}
