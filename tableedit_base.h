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

private:
    Ui::tableedit_base *ui;
};

#endif // TABLEEDIT_BASE_H
