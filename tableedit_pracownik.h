#ifndef TABLEEDIT_PRACOWNIK_H
#define TABLEEDIT_PRACOWNIK_H

#include <QWidget>

namespace Ui {
class tableedit_pracownik;
}

class tableedit_pracownik : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_pracownik(QWidget *parent = nullptr);
    ~tableedit_pracownik();
    void setValue(int row, QString id, QString imie, QString nazwisko, QString dataUrodzenia, QString email, QString telefon);

public slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    Ui::tableedit_pracownik *ui;
};

#endif // TABLEEDIT_PRACOWNIK_H
