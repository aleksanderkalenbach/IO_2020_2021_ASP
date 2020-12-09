#include "mainwindow.h"
#include "login.h"
#include "grupypanel.h"
#include "zajeciapanel.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QLayout>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


  setWindowTitle("Szkoła pływania");
  setCentralWidget(new QWidget(this));



  QToolBar *toolbar = addToolBar("Main toolbar");
  toolbar->setIconSize(QSize(128,32));
  toolbar->addAction(QIcon(":/icon/house.png"),"Start");
  toolbar->addSeparator();
  grupy = toolbar->addAction(QIcon(":/icon/users_5.png"),"Grupy");
  grupy->setCheckable(true);
  zajecia = toolbar->addAction(QIcon(":/icon/calendar_add.png"),"Zajecia");
  zajecia->setCheckable(true);
  toolbar->addSeparator();
  toolbar->addAction(QIcon(":/icon/client_account_template.png"),"Kadry");
  toolbar->addAction(QIcon(":/icon/coins.png"),"Ksiegowosc");
  toolbar->addAction(QIcon(":/icon/user_oldman.png"),"Zarzad");
  toolbar->addSeparator();
  toolbar->addAction(QIcon(":/icon/wyjscie.png"),"Zamknij");

  connect(grupy, SIGNAL(triggered()), this, SLOT(pokazGrupy()));
  connect(zajecia, SIGNAL(triggered()), this, SLOT(pokazZajecia()));


}

MainWindow::~MainWindow()
{}

void MainWindow::pokazGrupy()
{

    GrupyPanel *o = new GrupyPanel(this);

    if(grupy->isChecked())
    {
        if(zajecia->isChecked())
        {
            zajecia->setChecked(false);

        }
        dock->setWindowTitle("Grupy");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(o);

        o->setMinimumSize(200,600);
        dock->setVisible(true);
    }
    else
    {
        dock->setVisible(false);
    }

}

void MainWindow::pokazZajecia()
{
    zajeciapanel *o = new zajeciapanel(this);

     if(zajecia->isChecked())
    {
         if(grupy->isChecked())
         {
             grupy->setChecked(false);

         }
        dock->setWindowTitle("Zajęcia");
        dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable & ~QDockWidget::DockWidgetMovable & ~QDockWidget::DockWidgetFloatable); // wylacza przesuwanie widgetu
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(o);

        o->setMinimumSize(200,300);
        dock->setVisible(true);
    }
    else
    {
        dock->setVisible(false);
    }
}


