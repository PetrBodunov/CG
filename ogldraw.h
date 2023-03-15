#ifndef OGLDRAW_H
#define OGLDRAW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QString>
#include <QMouseEvent>
#include <QVector>
#include <QRubberBand>
#include "point.h"
#include <cmath>
#include <map>
#include <QGuiApplication>


class OGLDraw : public QOpenGLWidget, public QOpenGLFunctions
{
protected:
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

public:
    QColor cur_color = Qt::white;
    int cur_point_size = 20;
    int cur_line_size = 5;
    QVector<Point> points;
    int start_width;
    int start_height;
    int iter;

    int c_p = 6;
    int r = 200;
    int x0;
    int y0;
    int rotate_x = 1;


    OGLDraw(QWidget* pwgt = NULL);

    void draw();

    void draw_circles();

    void make_points();

    void wheelEvent(QWheelEvent *event) override;

    void change_points_coord();
};

#endif // OGLDRAW_H
