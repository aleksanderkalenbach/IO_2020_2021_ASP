#ifndef STARTPANEL_H
#define STARTPANEL_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class startpanel;
}

class startpanel : public QWidget
{
    Q_OBJECT

public:
    explicit startpanel(QWidget *parent = nullptr);
    ~startpanel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::startpanel *ui;
};

#endif // STARTPANEL_H
