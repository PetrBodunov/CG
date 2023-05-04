#ifndef OGLDRAW_H
#define OGLDRAW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QString>
#include <QMouseEvent>
#include <QVector>
#include "point.h"
#include <cmath>
#include <QOpenGLShaderProgram>


class OGLDraw : public QOpenGLWidget, public QOpenGLFunctions
{
protected:
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

public:
    int cur_line_size = 2;
    QColor cur_color = QColor(QColorConstants::Svg::purple);
    QVector<Point> points;
    QVector<Point> points_sh;
    int start_width;
    int start_height;
    bool is_clear = false;
    QString type = "Standart Bezier function";


    bool is_point = false;
    QOpenGLShaderProgram sh_program;
    bool turn_shader = false;
    GLfloat projection_mat[16];
    GLfloat modelview_mat[16];

    OGLDraw(QWidget* pwgt = NULL);

    void mousePressEvent(QMouseEvent* apEvent) override;
    void draw();
    void draw_bezier_func();
    void draw_without_bezier_func();
};

#endif // OGLDRAW_H
