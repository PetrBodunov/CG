#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

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
    void on_quitButton_clicked();

    void on_primitivesBox_currentTextChanged(const QString &arg1);

    void on_colorButton_clicked();

    void on_clearButton_clicked();

    void on_lineSlider_sliderMoved(int position);

    void on_pointlSlider_sliderMoved(int position);

    void on_scissorCheck_stateChanged(int arg1);

    void on_alphaCheck_stateChanged(int arg1);

    void on_alphaBox_currentTextChanged(const QString &arg1);

    void on_transparencySlider_sliderMoved(int position);

    void on_refSlider_sliderMoved(int position);

    void on_blendCheck_stateChanged(int arg1);

    void on_sfactorBox_currentTextChanged(const QString &arg1);

    void on_dfactorBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
