#ifndef SQLMODIFYSPOTKANIE_H
#define SQLMODIFYSPOTKANIE_H

#include <QDialog>

namespace Ui {
class sqlmodifyspotkanie;
}

class sqlmodifyspotkanie : public QDialog
{
    Q_OBJECT

public:
    explicit sqlmodifyspotkanie(QWidget *parent = nullptr);
    ~sqlmodifyspotkanie();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::sqlmodifyspotkanie *ui;
};

#endif // SQLMODIFYSPOTKANIE_H
