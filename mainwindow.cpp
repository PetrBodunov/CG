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

void MainWindow::on_cubeXSlider_valueChanged(int value)
{
    ui->openGLWidget->c->shift.setX((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeYSlider_valueChanged(int value)
{
    ui->openGLWidget->c->shift.setY((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeZSlider_valueChanged(int value)
{
    ui->openGLWidget->c->shift.setZ((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeASlider_valueChanged(int value)
{
    ui->openGLWidget->c->a = (float)value / 100;
    ui->openGLWidget->c->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeAngleSlider_valueChanged(int value)
{
    ui->openGLWidget->c->angle = value;
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereXSlider_valueChanged(int value)
{
    ui->openGLWidget->s->shift.setX((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereYSlider_valueChanged(int value)
{
    ui->openGLWidget->s->shift.setY((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereZSlider_valueChanged(int value)
{
    ui->openGLWidget->s->shift.setZ((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereRSlider_valueChanged(int value)
{
    ui->openGLWidget->s->R = (float)value / 100;
    ui->openGLWidget->s->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereAngleSlider_valueChanged(int value)
{
    ui->openGLWidget->s->angle = (float)value;
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereSlicesSlider_valueChanged(int value)
{
    ui->openGLWidget->s->slices = value;
    ui->openGLWidget->s->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereSpectreSlider_valueChanged(int value)
{
    ui->openGLWidget->s->stacks = value;
    ui->openGLWidget->s->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1XSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->shift.setX((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1YSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->shift.setY((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1ZSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->shift.setZ((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1RSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->R = (float)value / 100;
    ui->openGLWidget->sf1->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1RinSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->r_in = (float)value / 100;
    ui->openGLWidget->sf1->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1AngleSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->angle = value;
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1SlicersSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->slices = value;
    ui->openGLWidget->sf1->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1SlidersSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->stacks = value;
    ui->openGLWidget->sf1->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2XSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->shift.setX((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2YSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->shift.setY((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2ZSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->shift.setZ((float)value / 100);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2HSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->h = (float)value / 100;
    ui->openGLWidget->sf2->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2RSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->r = (float)value / 100;
    ui->openGLWidget->sf2->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2AngleSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->angle = value;
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2SlicesSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->slices = value;
    ui->openGLWidget->sf2->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2StacksSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->stacks = value;
    ui->openGLWidget->sf2->make_coords();
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeScaleXSlider_valueChanged(int value)
{
    ui->openGLWidget->c->scale.setX((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeScaleYSlider_valueChanged(int value)
{
    ui->openGLWidget->c->scale.setY((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_cubeScaleZSlider_valueChanged(int value)
{
    ui->openGLWidget->c->scale.setZ((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereScaleXSlider_valueChanged(int value)
{
    ui->openGLWidget->s->scale.setX((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereScaleYSlider_valueChanged(int value)
{
    ui->openGLWidget->s->scale.setY((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sphereScaleZSlider_valueChanged(int value)
{
    ui->openGLWidget->s->scale.setZ((float)value / 10);
    ui->openGLWidget->repaint();
}



void MainWindow::on_sf1ScaleXSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->scale.setX((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1ScaleYSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->scale.setY((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf1ScaleZSlider_valueChanged(int value)
{
    ui->openGLWidget->sf1->scale.setZ((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2ScaleXSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->scale.setX((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2ScaleYSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->scale.setY((float)value / 10);
    ui->openGLWidget->repaint();
}


void MainWindow::on_sf2ScaleZSlider_valueChanged(int value)
{
    ui->openGLWidget->sf2->scale.setZ((float)value / 10);
    ui->openGLWidget->repaint();
}

