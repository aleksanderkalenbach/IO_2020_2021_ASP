#include "mainwindow.h"

#include <QToolBar>
#include <QIcon>
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


  setWindowTitle("Szkoła pływania");
  setCentralWidget(new QWidget(this));



  QToolBar *toolbar = addToolBar("Main toolbar");
  toolbar->setIconSize(QSize(128,32));
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/house.png"),"Start");
  toolbar->addSeparator();
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/users_5.png"),"Grupy");
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/calendar_add.png"),"Zajecia");
  toolbar->addSeparator();
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/client_account_template.png"),"Kadry");
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/coins.png"),"Ksiegowosc");
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/user_oldman.png"),"Zarzad");
  toolbar->addSeparator();
  toolbar->addAction(QIcon("/Users/aleks/OneDrive/Dokumenty/IO_20_21/icons/wyjscie.png"),"Zamknij");


}

MainWindow::~MainWindow()
{}

