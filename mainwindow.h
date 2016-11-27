#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usbcamera.h"
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_btnShow_clicked();

private:
    Ui::MainWindow *ui;
    usbCamera camera;
};

#endif // MAINWINDOW_H
