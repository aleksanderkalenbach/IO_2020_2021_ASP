#ifndef SQLMODIFY_H
#define SQLMODIFY_H

#include <QDialog>

namespace Ui {
class SqlModify;
}

class SqlModify : public QDialog
{
    Q_OBJECT

public:
    explicit SqlModify(QWidget *parent = nullptr);
    ~SqlModify();
    QString Imie;
    QString Nazwisko;


private slots:
    void on_buttonBox_accepted();

private:
    Ui::SqlModify *ui;
};

#endif // SQLMODIFY_H
