#ifndef ZAJECIAPANEL_H
#define ZAJECIAPANEL_H

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

private:
    Ui::zajeciapanel *ui;
};

#endif // ZAJECIAPANEL_H
