#ifndef TABLEEDIT_OBECNOSCI_H
#define TABLEEDIT_OBECNOSCI_H

#include <QWidget>

namespace Ui {
class tableedit_obecnosci;
}

class tableedit_obecnosci : public QWidget
{
    Q_OBJECT

public:
    explicit tableedit_obecnosci(QWidget *parent = nullptr);
    void setValue(int row, QString id, QString uczestnik, QString zajecia);
    ~tableedit_obecnosci();

public slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tableedit_obecnosci *ui;
};

#endif // TABLEEDIT_OBECNOSCI_H
