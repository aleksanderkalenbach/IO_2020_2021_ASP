#include "sqlmodifyspotkanie.h"
#include "ui_sqlmodifyspotkanie.h"
#include "tableedit_spotkanie.h"

#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

sqlmodifyspotkanie::sqlmodifyspotkanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sqlmodifyspotkanie)
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
        query.exec("SELECT Nazwa FROM Kurs where Aktywny = 1");
        while(query.next())
        {
            this->ui->comboBoxKurs->addItem(query.value(0).toString());
        }

        db.close();
    }

}

sqlmodifyspotkanie::~sqlmodifyspotkanie()
{
    delete ui;
}

void sqlmodifyspotkanie::on_buttonBox_accepted()
{
    QString Data = ui->lineData->text();
    QString nazwaKursu = this->ui->comboBoxKurs->currentText();

    if(Data.isEmpty() || nazwaKursu.isEmpty())
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
        query.prepare("SELECT ID_kurs FROM Kurs where Nazwa = :Nazwa");
        query.bindValue(0,nazwaKursu);
        query.exec();
        if(query.next())
        {
            QString ID_Kurs = query.value(0).toString();
            qDebug() << ID_Kurs;
            query.prepare("INSERT INTO Spotkanie (Data, Kurs_ID_kurs, Aktywny)"
                          "VALUES (?, ?, DEFAULT)");
            query.addBindValue(Data);
            query.addBindValue(ID_Kurs);
            query.exec();
        }
        db.close();
    }
}
