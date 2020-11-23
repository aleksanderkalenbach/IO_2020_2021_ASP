#include "grupypanel.h"
#include "ui_grupypanel.h"

GrupyPanel::GrupyPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GrupyPanel)
{
    ui->setupUi(this);
}


GrupyPanel::~GrupyPanel()
{
    delete ui;
}
