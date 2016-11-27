#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    connect(&camera, SIGNAL(frameIsReady(const u_int8_t*,int)), SLOT(cameraImageIsReady(const u_int8_t*,int)));
    camera.loadConfig();
    camera.connect();
    ui->btnStart->setText("connected");
}

void MainWindow::cameraImageIsReady(const u_int8_t *data, int imageSize)
{
//    QFile file("/tmp/image");
//    file.open(QFile::WriteOnly);
//    file.write((const char *)data,imageSize);
    QImage *im = new QImage((const uchar*)data,1600,1200,QImage::Format_RGB888);

    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*im));
    ui->graphicsView->show();

}

void MainWindow::on_btnShow_clicked()
{
    camera.getFrame();
}
