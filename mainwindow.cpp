#include "mainwindow.h"
#include "login.h"
#include "grupypanel.h"
#include "zajeciapanel.h"
#include "startpanel.h"
#include "tableedit_base.h"
#include "tableedit_pracownik.h"
#include "pracownikpanel.h"

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

      grupy = toolbar->addAction(QIcon(":/icon/users_5.png"),"Grupy");
      grupy->setCheckable(true);
      zajecia = toolbar->addAction(QIcon(":/icon/calendar_add.png"),"Zajecia");
      zajecia->setCheckable(true);

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
    GrupyPanel *lewyPanel = new GrupyPanel(this);
    tableedit_base *tabela = new tableedit_base(this);

    if(grupy->isChecked())
    {
        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        if(start->isChecked())
        {
            start->setChecked(false);
        }


        dock->setWindowTitle("Grupy");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(lewyPanel);
        lewyPanel->setMinimumSize(200,300);
        dock->setVisible(true);
        setCentralWidget(tabela);

        tabela->on_pushButton_4_clicked();//wstępne wyświetlenie rekordów

    }
    else
    {
        dock->setVisible(false);
    }

}

void MainWindow::pokazZajecia()
{
    zajeciapanel *lewyPanel = new zajeciapanel(this);
    QCalendarWidget *calendar = new QCalendarWidget(this);

     if(zajecia->isChecked())
    {
         if(grupy->isChecked())
         {
             grupy->setChecked(false);

         }
         if(start->isChecked())
         {
             start->setChecked(false);

         }


        dock->setWindowTitle("Zajęcia");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(lewyPanel);

        setCentralWidget(calendar);

        lewyPanel->setMinimumSize(200,300);
        dock->setVisible(true);
    }
    else
    {
        dock->setVisible(false);
    }
}

void MainWindow::pokazStart()
{
    startpanel *lewyPanel = new startpanel(this);


     if(start->isChecked())
    {
         if(grupy->isChecked())
         {
             grupy->setChecked(false);

         }
         if(zajecia->isChecked())
         {
             zajecia->setChecked(false);

         }

        takeCentralWidget();
        dock->setWindowTitle("Start");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);

        dock->setWidget(lewyPanel);
        lewyPanel->setMinimumSize(200,300);
        dock->setVisible(true);
    }
    else
    {
        dock->setVisible(false);
     }
}

void MainWindow::pokazPracownicy()
{
    pracownikpanel *lewyPanel = new pracownikpanel(this);
    tableedit_pracownik *tabela = new tableedit_pracownik(this);

    if(pracownicy->isChecked())
    {
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

        dock->setWindowTitle("Pracownicy");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(lewyPanel);
        lewyPanel->setMinimumSize(200,300);
        dock->setVisible(true);
        setCentralWidget(tabela);

        tabela->on_pushButton_4_clicked();//wstępne wyświetlenie rekordów

    }
    else
    {
        dock->setVisible(false);
    }
}


