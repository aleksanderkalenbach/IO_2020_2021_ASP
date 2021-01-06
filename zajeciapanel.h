#ifndef ZAJECIAPANEL_H
#define ZAJECIAPANEL_H

#include "tableedit_obecnosci.h"

#include <QWidget>

namespace Ui {
class zajeciapanel;
}

class zajeciapanel : public QWidget
{
    Q_OBJECT

public:
    explicit zajeciapanel(QWidget *parent = nullptr);

    ~zajeciapanel();

public slots:
   void on_pushButton_2_clicked();

private:
    Ui::zajeciapanel *ui;
};

#endif // ZAJECIAPANEL_H
