#ifndef TABLEEDIT_KURSY_PRACOWNIK_H
#define TABLEEDIT_KURSY_PRACOWNIK_H

#include <QWidget>

namespace Ui {
class tableedit_kursy_pracownik;
}

class tableedit_kursy_pracownik : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_kursy_pracownik(QWidget *parent = nullptr);
    ~tableedit_kursy_pracownik();
    void setValue(int row, QString nazwa, QString data_rozpoczecia, QString data_zakonczenia, QString cena, QString poziom, QString wiek, QString prowadzacy);

public slots:
    void on_pushButton_odswiez_clicked();

private slots:
    void on_pushButton_dodaj_clicked();

    void on_pushButton_usun_clicked();

    void on_pushButton_zmien_clicked();


private:
    Ui::tableedit_kursy_pracownik *ui;
};

#endif // TABLEEDIT_KURSY_PRACOWNIK_H
