#include "mainwindow.h"
#include "login.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login login;

    if(login.exec() == QDialog::Accepted){
        MainWindow w;
        w.resize(1200,800);
        w.show();
        return a.exec();
      }
    else return 0;
}
