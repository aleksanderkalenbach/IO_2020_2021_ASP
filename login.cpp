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
    haslo = QString("%1").arg(QString(QCryptographicHash::hash(haslo.toUtf8(),QCryptographicHash::Md5).toHex()));


    if(login == "Prowadzacy" && haslo == "3fc0a7acf087f549ac2b266baf94b8b1")
    {
        accept();
    }
    else if(login == "Student" && haslo == "d8578edf8458ce06fbc5bb76a58c5ca4")
    {
        accept();
    }
    else if(login == "hr" && haslo == "48474f975022f960bc2afbe49be581e8")
    {
        accept();
    }
    else
    {
        ui->labelMsg->setText("Zły login lub hasło");
    }
}
