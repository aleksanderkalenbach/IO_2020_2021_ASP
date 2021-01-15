#ifndef TABLEEDIT_SPOTKANIE_H
#define TABLEEDIT_SPOTKANIE_H

#include <QWidget>

namespace Ui {
class tableedit_spotkanie;
}

class tableedit_spotkanie : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_spotkanie(QWidget *parent = nullptr);
    ~tableedit_spotkanie();
    void setValue(int row, QString data, QString grupa);

public slots:
    void on_pushButton_odswiez_clicked();

private slots:
    void on_pushButton_dodaj_clicked();

    void on_pushButton_usun_clicked();

    void on_pushButton_zmien_clicked();

private:
    Ui::tableedit_spotkanie *ui;
};

#endif // TABLEEDIT_SPOTKANIE_H
