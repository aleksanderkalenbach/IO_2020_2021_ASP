#ifndef PRACOWNIKPANEL_H
#define PRACOWNIKPANEL_H

#include <QWidget>

namespace Ui {
class pracownikpanel;
}

class pracownikpanel : public QWidget
{
    Q_OBJECT

public:
    explicit pracownikpanel(QWidget *parent = nullptr);
    ~pracownikpanel();

private:
    Ui::pracownikpanel *ui;
};

#endif // PRACOWNIKPANEL_H
