#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_primitivesBox_currentTextChanged(const QString &arg1)
{
    ui->openGLWidget->type = arg1;
    ui->openGLWidget->repaint();
}

void MainWindow::on_colorButton_clicked()
{
    ui->openGLWidget->cur_color = QColorDialog::getColor(Qt::white, this);
    if(ui->openGLWidget->cur_color.isValid()) {
        QString qss = QString("background-color: %1").arg(ui->openGLWidget->cur_color.name());
        ui->colorButton->setStyleSheet(qss);
        ui->colorButton->setText("");
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->openGLWidget->is_clear = true;
    ui->openGLWidget->repaint();
}

void MainWindow::on_lineSlider_sliderMoved(int position)
{
    ui->openGLWidget->cur_line_size = position;
    ui->openGLWidget->repaint();
}

void MainWindow::on_pointlSlider_sliderMoved(int position)
{
    ui->openGLWidget->cur_point_size = position;
    ui->openGLWidget->repaint();
}

void MainWindow::on_scissorCheck_stateChanged(int arg1)
{
    if (arg1 == 0){
        ui->openGLWidget->is_scissor_test = false;
        ui->openGLWidget->rubberBand = NULL;
        ui->openGLWidget->rubberBand.reset(nullptr);
//        delete(ui->openGLWidget->rubberBand);
    }
    else
        ui->openGLWidget->is_scissor_test = true;
    ui->openGLWidget->repaint();
}

void MainWindow::on_alphaCheck_stateChanged(int arg1)
{
    if (arg1 == 0){
        ui->openGLWidget->is_alpha_test = false;
    }
    else
        ui->openGLWidget->is_alpha_test = true;
    ui->openGLWidget->repaint();
}


void MainWindow::on_alphaBox_currentTextChanged(const QString &arg1)
{
    ui->openGLWidget->type_alpha = arg1;
    ui->openGLWidget->repaint();
}

void MainWindow::on_transparencySlider_sliderMoved(int position)
{
    ui->openGLWidget->cur_transparency = (float)position / ui->transparencySlider->maximum();
    ui->openGLWidget->repaint();
}


void MainWindow::on_refSlider_sliderMoved(int position)
{
    ui->openGLWidget->ref_alpha = (float)position / ui->refSlider->maximum();
    ui->openGLWidget->repaint();
}


void MainWindow::on_blendCheck_stateChanged(int arg1)
{
    if (arg1 == 0){
        ui->openGLWidget->is_blend = false;
    }
    else
        ui->openGLWidget->is_blend = true;
    ui->openGLWidget->repaint();
}


void MainWindow::on_sfactorBox_currentTextChanged(const QString &arg1)
{
    ui->openGLWidget->type_sfactor = arg1;
    ui->openGLWidget->repaint();
}


void MainWindow::on_dfactorBox_currentTextChanged(const QString &arg1)
{
    ui->openGLWidget->type_dfactor = arg1;
    ui->openGLWidget->repaint();
}

