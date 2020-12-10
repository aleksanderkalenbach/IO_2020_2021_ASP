#include "startpanel.h"
#include "ui_startpanel.h"
#include "QMessageBox"

startpanel::startpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startpanel)
{
    ui->setupUi(this);
}

startpanel::~startpanel()
{
    delete ui;
}

void startpanel::on_pushButton_clicked()
{
    QMessageBox *msg = new QMessageBox(this);
    msg->information(0, "Autorzy", "Work in progress!");
}

void startpanel::on_pushButton_2_clicked()
{
    QMessageBox *msg = new QMessageBox(this);
    msg->information(0, "Autorzy", "Aleksander Kalenbach\n Krzysztof Kosmalski\n Przemysław Pułanecki");
}

void startpanel::on_pushButton_3_clicked()
{
    QMessageBox *msg = new QMessageBox(this);
    msg->information(0, "Autorzy", "Aplikacja zarządzania szkołą pływacką zawierająca połączenie z bazą danych. Aplikacja będzie zawierała informacje kadrowe, księgowe oraz stan asortymentu od strony pracowniczej oraz informację o ocenach i kursach od strony klientów. Po zalogowaniu się prowadzący będą mogli zarządzać grupami(dodawanie oraz usuwanie grup i uczestników), sprawdzać obecność, dodawać oraz odwoływać terminy zajęć a uczestnicy będą mogli zapisać się na kursy oraz sprawdzić daty spotkań.");
}


