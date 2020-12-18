#ifndef SQLMODIFYPRACOWNIK_H
#define SQLMODIFYPRACOWNIK_H

#include <QDialog>

namespace Ui {
class sqlmodifypracownik;
}

class sqlmodifypracownik : public QDialog
{
    Q_OBJECT

public:
    explicit sqlmodifypracownik(QWidget *parent = nullptr);
    ~sqlmodifypracownik();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::sqlmodifypracownik *ui;
};

#endif // SQLMODIFYPRACOWNIK_H
