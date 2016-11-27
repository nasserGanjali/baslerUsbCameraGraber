#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include "usbcamera.h"
#include "stringmodel.h"

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
    void cameraImageIsReady(const u_int8_t *data, int imageSize);
    void on_btnShow_clicked();


private:
    Ui::MainWindow *ui;
    usbCamera camera;
    stringModel stringModelIns;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
