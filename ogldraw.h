#ifndef OGLDRAW_H
#define OGLDRAW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QString>
#include <QMouseEvent>
#include <QVector>
#include <cmath>
#include <QKeyEvent>
#include <GL/glu.h>

#include "sphere.h"
#include "cube.h"
#include "specialfig1.h"
#include "specialfig2.h"


class OGLDraw : public QOpenGLWidget, public QOpenGLFunctions
{
protected:
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

public:
    int start_width;
    int start_height;


    float xe = 0, ye = 0.5, ze = 2.5;
    float xev = 0, yev = 0, zev = 0;
    float xed = 0, zed = -0.05;
    int angley = 0;

    Cube* c = new Cube(0.5, QVector3D(0, 1, 0), QVector3D(0.5,0.5,-0.4), QVector3D(1,1,1));
    Sphere* s = new Sphere(0.4, 15, 15, QVector3D(1, 0, 0), QVector3D(0.5,0.5,0.4), QVector3D(1,1,1));
    SpecialFig1* sf1 = new SpecialFig1(0.4, 0.2, 15, 15, QVector3D(1, 0, 0), QVector3D(-0.5,0.5,0.4), QVector3D(1,1,1));
    SpecialFig2* sf2 = new SpecialFig2(0.6, 0.4, 4, 15, QVector3D(1, 0, 0), QVector3D(-0.2,-0.3,-0.4), QVector3D(1,1,1));

    OGLDraw(QWidget* pwgt = NULL);
    ~OGLDraw();

    void moveCamera();
    void draw_cube(Cube* objectmodel, QColor color);
    void draw_sphere(Sphere* objectmodel, QColor color);
    void draw_coordinate_system();
    void draw_specialfig1(SpecialFig1* obj, QColor color);
    void draw_specialfig2(SpecialFig2* objectmodel, QColor color);

    void keyPressEvent(QKeyEvent *ev) override;
};

#endif // OGLDRAW_H
