#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_iterationSlider_sliderMoved(int position)
{
    ui->openGLWidget->iter = position;
    ui->openGLWidget->points.clear();
    ui->openGLWidget->make_points();
    ui->openGLWidget->repaint();
}

