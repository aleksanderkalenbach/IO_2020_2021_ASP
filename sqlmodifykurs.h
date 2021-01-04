#ifndef SQLMODIFYKURS_H
#define SQLMODIFYKURS_H

#include <QDialog>

namespace Ui {
class sqlmodifykurs;
}

class sqlmodifykurs : public QDialog
{
    Q_OBJECT

public:
    explicit sqlmodifykurs(QDialog *parent = nullptr);
    ~sqlmodifykurs();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::sqlmodifykurs *ui;
};

#endif // SQLMODIFYKURS_H
