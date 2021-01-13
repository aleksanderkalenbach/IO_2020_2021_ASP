#ifndef TABLEEDIT_BASE_H
#define TABLEEDIT_BASE_H

#include <QWidget>

namespace Ui {
class tableedit_base;
}

class tableedit_base : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_base(QWidget *parent = nullptr);
    ~tableedit_base();
    void setValue(int row, QString imie, QString nazwisko, QString dataUrodzenia, QString email, QString kwotaDoZaplaty);
    //Ui::tableedit_base *zwrocUI() {return ui;};

public slots:
    void on_pushButton_4_clicked();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::tableedit_base *ui;
};

#endif // TABLEEDIT_BASE_H
