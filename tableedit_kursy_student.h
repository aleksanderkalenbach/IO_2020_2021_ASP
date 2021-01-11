#ifndef TABLEEDIT_KURSY_STUDENT_H
#define TABLEEDIT_KURSY_STUDENT_H

#include <QWidget>

namespace Ui {
class tableedit_kursy_student;
}

class tableedit_kursy_student : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_kursy_student(QWidget *parent = nullptr);
    ~tableedit_kursy_student();
    void setValue(int row, QString nazwa, QString data_rozpoczecia, QString data_zakonczenia, QString cena, QString poziom, QString wiek, QString prowadzacy);

public slots:
    void on_pushButton_odswiez_clicked();

private:
    Ui::tableedit_kursy_student *ui;
};

#endif // TABLEEDIT_KURSY_STUDENT_H
