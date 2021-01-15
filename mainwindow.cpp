#include "mainwindow.h"
#include "login.h"
#include "tableedit_base.h"
#include "tableedit_pracownik.h"
#include "tableedit_kursy_student.h"
#include "tableedit_kursy_pracownik.h"
#include "tableedit_spotkanie.h"
#include "tableedit_obecnosci.h"
#include "startview.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QLayout>
#include <QDockWidget>
#include <QStackedWidget>
#include <QCalendarWidget>
#include <QtSql>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  Login login;
  if(login.exec() == QDialog::Accepted){

      setWindowTitle("Szkoła pływania");
      //setCentralWidget(new QWidget(this));



      QToolBar *toolbar = addToolBar("Main toolbar");
      toolbar->setIconSize(QSize(128,32));
      start = toolbar->addAction(QIcon(":/icon/house.png"),"Start");
      start->setCheckable(true);


      toolbar->addSeparator();

      grupy = toolbar->addAction(QIcon(":/icon/users_5.png"),"Uczestnicy");
      grupy->setCheckable(true);
      zajecia = toolbar->addAction(QIcon(":/icon/meeting_workspace.png"),"Zajecia");
      zajecia->setCheckable(true);
      kursy = toolbar->addAction(QIcon(":/icon/calendar_add.png"),"Kursy");
      kursy->setCheckable(true);
      obecnosc = toolbar->addAction(QIcon(":/icon/accept_document"),"Obecnosc");
      obecnosc->setCheckable(true);






      toolbar->addSeparator();

      if(login.login == "hr")
      {
          pracownicy = toolbar->addAction(QIcon(":/icon/client_account_template.png"),"Pracownicy");
          pracownicy->setCheckable(true);

          connect(pracownicy, SIGNAL(triggered()), this, SLOT(pokazPracownicy()));

          //toolbar->addAction(QIcon(":/icon/coins.png"),"Ksiegowosc");
          //toolbar->addAction(QIcon(":/icon/user_oldman.png"),"Zarzad");
          toolbar->addSeparator();
      }

      wyjdz = toolbar->addAction(QIcon(":/icon/wyjscie.png"),"Zamknij");

      connect(start,SIGNAL(triggered()),this, SLOT(pokazStart()));
      connect(grupy, SIGNAL(triggered()), this, SLOT(pokazGrupy()));
      connect(zajecia, SIGNAL(triggered()), this, SLOT(pokazZajecia()));
      connect(obecnosc, SIGNAL(triggered()),this,SLOT(pokazObecnosc()));

      if(login.login == "Student")
      {
          connect(kursy, SIGNAL(triggered()), this, SLOT(pokazKursy()));
      }
      else
      {
          connect(kursy, SIGNAL(triggered()), this, SLOT(pokazKursyPracownik()));
      }

      connect(wyjdz, SIGNAL(triggered()), this, SLOT(close()));
      }
  else
  {
     exit(1);
  }
}

MainWindow::~MainWindow()
{}

void MainWindow::pokazGrupy()
{

    tableedit_base *tabela = new tableedit_base(this);


        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }
        if(kursy->isChecked())
        {
            kursy->setChecked(false);
        }
        if(obecnosc->isChecked())
        {
            obecnosc->setChecked(false);
        }

        setCentralWidget(tabela);

        tabela->on_pushButton_4_clicked();//wstępne wyświetlenie rekordów



}

void MainWindow::pokazZajecia()
{

    tableedit_spotkanie *tabela = new tableedit_spotkanie(this);

         if(grupy->isChecked())
         {
             grupy->setChecked(false);

         }
         if(start->isChecked())
         {
             start->setChecked(false);
         }
         if(kursy->isChecked())
         {
             kursy->setChecked(false);
         }
         if(obecnosc->isChecked())
         {
             obecnosc->setChecked(false);
         }

        setCentralWidget(tabela);
        tabela->on_pushButton_odswiez_clicked();

}

void MainWindow::pokazKursy()
{

    tableedit_kursy_student *tabela = new tableedit_kursy_student(this);


        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }
        if(grupy->isChecked())
        {
            grupy->setCheckable(false);
        }
        if(obecnosc->isChecked())
        {
            obecnosc->setChecked(false);
        }

        setCentralWidget(tabela);

        tabela->on_pushButton_odswiez_clicked();//wstępne wyświetlenie rekordów

}

void MainWindow::pokazKursyPracownik()
{
    tableedit_kursy_pracownik *tabela = new tableedit_kursy_pracownik(this);


        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }
        if(grupy->isChecked())
        {
            grupy->setCheckable(false);
        }
        if(obecnosc->isChecked())
        {
            obecnosc->setChecked(false);
        }


        setCentralWidget(tabela);

        tabela->on_pushButton_odswiez_clicked();//wstępne wyświetlenie rekordów


}

void MainWindow::pokazStart()
{

    StartView *start =  new StartView(this);

         if(grupy->isChecked())
         {
             grupy->setChecked(false);

         }
         if(zajecia->isChecked())
         {
             zajecia->setChecked(false);
         }
         if(kursy->isChecked())
         {
             kursy->setChecked(false);
         }
         if(obecnosc->isChecked())
         {
             obecnosc->setChecked(false);
         }

         setCentralWidget(start);

}

void MainWindow::pokazPracownicy()
{
    tableedit_pracownik *tabela = new tableedit_pracownik(this);

        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }
        if(grupy->isChecked())
        {
            grupy->setChecked(false);
        }
        if(kursy->isChecked())
        {
            kursy->setChecked(false);
        }
        if(obecnosc->isChecked())
        {
            obecnosc->setChecked(false);
        }

        setCentralWidget(tabela);

        tabela->on_pushButton_4_clicked();//wstępne wyświetlenie rekordów


}

void MainWindow::pokazObecnosc()
{
    tableedit_obecnosci *tabela = new tableedit_obecnosci(this);

        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }
        if(grupy->isChecked())
        {
            grupy->setChecked(false);
        }
        if(kursy->isChecked())
        {
            kursy->setChecked(false);
        }

        setCentralWidget(tabela);

        tabela->on_pushButton_2_clicked();//wstępne wyświetlenie rekordów


}


