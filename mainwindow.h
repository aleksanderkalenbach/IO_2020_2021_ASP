#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDockWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    QAction *start;
    QAction *grupy;
    QAction *zajecia;
    QAction *wyjdz;
    QDockWidget *dock = new QDockWidget();
    QString login;



public slots:
    void pokazGrupy();
    void pokazZajecia();
    void pokazStart();


};
#endif // MAINWINDOW_H
