#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cubeXSlider_valueChanged(int value);

    void on_cubeYSlider_valueChanged(int value);

    void on_cubeZSlider_valueChanged(int value);

    void on_cubeASlider_valueChanged(int value);

    void on_cubeAngleSlider_valueChanged(int value);

    void on_sphereXSlider_valueChanged(int value);

    void on_sphereYSlider_valueChanged(int value);

    void on_sphereZSlider_valueChanged(int value);

    void on_sphereRSlider_valueChanged(int value);

    void on_sphereAngleSlider_valueChanged(int value);

    void on_sphereSlicesSlider_valueChanged(int value);

    void on_sphereSpectreSlider_valueChanged(int value);

    void on_sf1XSlider_valueChanged(int value);

    void on_sf1YSlider_valueChanged(int value);

    void on_sf1ZSlider_valueChanged(int value);

    void on_sf1RSlider_valueChanged(int value);

    void on_sf1RinSlider_valueChanged(int value);

    void on_sf1AngleSlider_valueChanged(int value);

    void on_sf1SlicersSlider_valueChanged(int value);

    void on_sf1SlidersSlider_valueChanged(int value);

    void on_sf2XSlider_valueChanged(int value);

    void on_sf2YSlider_valueChanged(int value);

    void on_sf2ZSlider_valueChanged(int value);

    void on_sf2HSlider_valueChanged(int value);

    void on_sf2RSlider_valueChanged(int value);

    void on_sf2AngleSlider_valueChanged(int value);

    void on_sf2SlicesSlider_valueChanged(int value);

    void on_sf2StacksSlider_valueChanged(int value);

    void on_cubeScaleXSlider_valueChanged(int value);

    void on_cubeScaleYSlider_valueChanged(int value);

    void on_cubeScaleZSlider_valueChanged(int value);

    void on_sphereScaleXSlider_valueChanged(int value);

    void on_sphereScaleYSlider_valueChanged(int value);

    void on_sphereScaleZSlider_valueChanged(int value);

    void on_sf1ScaleXSlider_valueChanged(int value);

    void on_sf1ScaleYSlider_valueChanged(int value);

    void on_sf1ScaleZSlider_valueChanged(int value);

    void on_sf2ScaleXSlider_valueChanged(int value);

    void on_sf2ScaleYSlider_valueChanged(int value);

    void on_sf2ScaleZSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
