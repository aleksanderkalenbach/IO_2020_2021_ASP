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
    QDockWidget *dock = new QDockWidget();

public slots:
    void pokazGrupy();


};
#endif // MAINWINDOW_H
