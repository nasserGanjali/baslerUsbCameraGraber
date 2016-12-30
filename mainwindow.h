#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include "usbcamera.h"
#include "stringmodel.h"

#define BUFFERSIZE 256
#define WIDTH 1600
#define HEIGHT 1200

namespace Ui {
class MainWindow;
}

//class usbCamera;
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
