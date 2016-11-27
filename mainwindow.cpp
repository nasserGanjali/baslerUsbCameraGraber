#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    camera.main();
}

void MainWindow::on_btnShow_clicked()
{
    char *data;
    data = (char *)malloc(1600*1200*3);
    QFile file("/tmp/file");
    file.open(QFile::ReadOnly);
    file.read(data,1600*1200*3);
    file.close();

    QImage *im = new QImage((const uchar*)data,1600,1200,QImage::Format_RGB888);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(*im));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
