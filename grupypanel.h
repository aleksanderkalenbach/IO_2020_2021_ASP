#ifndef GRUPYPANEL_H
#define GRUPYPANEL_H

#include <QWidget>

namespace Ui {
class GrupyPanel;
}

class GrupyPanel : public QWidget
{
    Q_OBJECT

public:
    explicit GrupyPanel(QWidget *parent = nullptr);
    ~GrupyPanel();

private:
    Ui::GrupyPanel *ui;
};

#endif // GRUPYPANEL_H
