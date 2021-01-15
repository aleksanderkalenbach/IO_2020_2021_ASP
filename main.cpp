#include "mainwindow.h"
#include "login.h"
#include "mainwindow.h"
#include <QtSql>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1175,675);
    w.show();
    return a.exec();
}
