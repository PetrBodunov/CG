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

class OGLDraw : public QOpenGLWidget, public QOpenGLFunctions
{
protected:
    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight) override;
    void paintGL() override;

public:
    QString type = "GL_POINTS";
    QColor cur_color = Qt::blue;
    int cur_point_size = 1;
    int cur_line_size = 1;
    QVector<Point> points;
    bool is_clear = false;
    int start_width;
    int start_height;

    bool is_scissor_test = false;
    bool is_alpha_test = false;
    bool is_blend = false;
    std::unique_ptr<QRubberBand> rubberBand;
    QPoint event_point;
    QString type_alpha = "GL_NEVER";
    float ref_alpha = 0;
    float cur_transparency = 1;
    QString type_sfactor = "GL_ZERO";
    QString type_dfactor = "GL_ZERO";
    std::map<QString, GLenum> sfactor_map = {{"GL_ZERO", GL_ZERO},
                                             {"GL_ONE", GL_ONE},
                                             {"GL_DST_COLOR", GL_DST_COLOR},
                                             {"GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR},
                                             {"GL_SRC_ALPHA", GL_SRC_ALPHA},
                                             {"GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA},
                                             {"GL_DST_ALPHA", GL_DST_ALPHA},
                                             {"GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA},
                                             {"GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE}
                                            };

    std::map<QString, GLenum> dfactor_map = {{"GL_ZERO", GL_ZERO},
                                             {"GL_ONE", GL_ONE},
                                             {"GL_SRC_COLOR", GL_SRC_COLOR},
                                             {"GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR},
                                             {"GL_SRC_ALPHA", GL_SRC_ALPHA},
                                             {"GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA},
                                             {"GL_DST_ALPHA", GL_DST_ALPHA},
                                             {"GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA}
                                            };

    OGLDraw(QWidget* pwgt = NULL);

    void draw(GLenum type);

    void draw_circles();

    void draw_scissor_test();

    void draw_alpha_test();

    void draw_blend();


    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent *apEvent) override;
    void mouseReleaseEvent(QMouseEvent *apEvent) override;
};

#endif // OGLDRAW_H
