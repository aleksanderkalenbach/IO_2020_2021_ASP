#ifndef STARTPANEL_H
#define STARTPANEL_H

#include <QWidget>

namespace Ui {
class startpanel;
}

class startpanel : public QWidget
{
    Q_OBJECT

public:
    explicit startpanel(QWidget *parent = nullptr);
    ~startpanel();

private:
    Ui::startpanel *ui;
};

#endif // STARTPANEL_H
