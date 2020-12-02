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
    QAction *grupy;
    QAction *zajecia;
    QDockWidget *dock = new QDockWidget();



public slots:
    void pokazGrupy();
    void pokazZajecia();


};
#endif // MAINWINDOW_H
