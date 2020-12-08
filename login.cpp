#include "login.h"
#include "ui_login.h"
#include <QCryptographicHash>
#include "mainwindow.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //QCryptographicHash studentHaslo(QCryptographicHash::Md5);
    //studentHaslo = (d8578edf8458ce06fbc5bb76a58c5ca4);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushOK_clicked()
{
    QString login = ui->lineLogin->text();
    QString haslo = ui->lineHaslo->text();
    this->login = login;
   // QByteArray ba = haslo.toLocal8Bit();
    //QCryptographicHash hash(QCryptographicHash::Md5);
    //hash.addData(ba);
   // hash.result().toHex();


    if(login == "Prowadzacy" && haslo == "qwerty123")
    {
        accept();
    }
    else if(login == "Student" && haslo == "qwerty")
    {
        accept();
    }
    else
    {
        ui->labelMsg->setText("Zły login lub hasło");

    }
}
