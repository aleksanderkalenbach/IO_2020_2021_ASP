#include "mainwindow.h"
#include "login.h"

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
  toolbar->addAction(QIcon(":/icon/house.png"),"Start");
  toolbar->addSeparator();
  toolbar->addAction(QIcon(":/icon/users_5.png"),"Grupy");
  toolbar->addAction(QIcon(":/icon/calendar_add.png"),"Zajecia");
  toolbar->addSeparator();
  toolbar->addAction(QIcon(":/icon/client_account_template.png"),"Kadry");
  toolbar->addAction(QIcon(":/icon/coins.png"),"Ksiegowosc");
  toolbar->addAction(QIcon(":/icon/user_oldman.png"),"Zarzad");
  toolbar->addSeparator();
  toolbar->addAction(QIcon(":/icon/wyjscie.png"),"Zamknij");


}

MainWindow::~MainWindow()
{}



