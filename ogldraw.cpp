#include "ogldraw.h"

int comp(const Point* a, const Point*b)
{
    return a->coord.x() - b->coord.x();
}

OGLDraw::OGLDraw(QWidget* pwgt) : QOpenGLWidget(pwgt)
{
}

void OGLDraw::initializeGL()
{
    initializeOpenGLFunctions();
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
//    pFunc->glClearColor(211/255.0f,211/255.0f,211/255.0f, 1.0f);
    pFunc->glClearColor(0, 0, 0, 1.0f);

    start_width = this->width();
    start_height = this->height();
}

void OGLDraw::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, nWidth, nHeight, 0, -1, 1);
    glViewport (0, 0, (GLint)nWidth, (GLint)nHeight);

}

void OGLDraw::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();

    if (is_clear){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        is_clear = false;
        points.clear();
    }
}

void OGLDraw::draw()
{
    glLineWidth(cur_line_size);

    if (type == "Standart Bezier function")
        draw_bezier_func();
    else
        draw_without_bezier_func();
}

void OGLDraw::draw_bezier_func()
{
    for (int i = 0; i < points.size(); i += 3){
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1,0x0101);
        glColor3f(255, 255, 0);
        glBegin(GL_LINE_STRIP);
            for (int j = i; j < points.size() && j < i + 4; j++){
                glVertex2f(points[j].coord.rx() * this->width() / start_width,
                           points[j].coord.ry() * this->height() / start_height);
            }
        glEnd();
        glDisable(GL_LINE_STIPPLE);

        if (i + 3 < points.size()){
            glBegin(GL_LINES);
                for (float t = 0; t < 1; t += 0.01){
                    QPoint p;
                    p.rx() = pow(1 - t, 3) * points[i].coord.rx() + 3 * t * pow((t-1), 2) * points[i + 1].coord.rx() +
                            3 * pow(t, 2) * (1 - t) * points[i + 2].coord.rx() + pow(t, 3) * points[i + 3].coord.rx();
                    p.ry() = pow(1 - t, 3) * points[i].coord.ry() + 3 * t * pow((t-1), 2) * points[i + 1].coord.ry() +
                            3 * pow(t, 2) * (1 - t) * points[i + 2].coord.ry() + pow(t, 3) * points[i + 3].coord.ry();
                    glColor3f(180, 0, 180);
                    glVertex2f (p.rx() * this->width() / start_width, p.ry() * this->height() / start_height);
                }
            glEnd();
        }
    }
}

void OGLDraw::draw_without_bezier_func()
{
    for (int i = 0; i < points.size(); i += 3){
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1,0x0101);
        glColor3f(255, 255, 0);
        glBegin(GL_LINE_STRIP);
            for (int j = i; j < points.size() && j < i + 4; j++){
                glVertex2f(points[j].coord.rx() * this->width() / start_width,
                           points[j].coord.ry() * this->height() / start_height);
            }
        glEnd();
        glDisable(GL_LINE_STIPPLE);

        if (i + 3 < points.size()){
            glBegin(GL_LINES);
                for (float t = 0; t < 1; t += 0.01){
                    QPoint E(t * points[i + 1].coord.rx() + (1 - t) * points[i].coord.rx(),
                             t * points[i + 1].coord.ry() + (1 - t) * points[i].coord.ry());
                    QPoint F(t * points[i + 2].coord.rx() + (1 - t) * points[i + 1].coord.rx(),
                             t * points[i + 2].coord.ry() + (1 - t) * points[i + 1].coord.ry());
                    QPoint G(t * points[i + 3].coord.rx() + (1 - t) * points[i + 2].coord.rx(),
                             t * points[i + 3].coord.ry() + (1 - t) * points[i + 2].coord.ry());
                    QPoint H(t * F.rx() + (1 - t) * E.rx(),
                             t * F.ry() + (1 - t) * E.ry());
                    QPoint I(t * G.rx() + (1 - t) * F.rx(),
                             t * G.ry() + (1 - t) * F.ry());
                    QPoint J(t * I.rx() + (1 - t) * H.rx(),
                             t * I.ry() + (1 - t) * H.ry());
                    glColor3f(180, 0, 180);
                    glVertex2f (J.rx() * this->width() / start_width, J.ry() * this->height() / start_height);
                }
            glEnd();
        }
    }

}

void OGLDraw::mousePressEvent(QMouseEvent* apEvent)
{
    QPoint p = apEvent->pos();
    p.rx() = p.rx() * start_width / this->width();
    p.ry() = p.ry() * start_height / this->height();
    Point point(p, cur_color);
    points.append(point);
    repaint();
}


