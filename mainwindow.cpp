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

void MainWindow::on_clearButton_clicked()
{
    ui->openGLWidget->is_clear = true;
    ui->openGLWidget->repaint();
}


void MainWindow::on_constructioTypeBox_currentTextChanged(const QString &arg1)
{
    ui->openGLWidget->type = arg1;
    ui->openGLWidget->repaint();
}

