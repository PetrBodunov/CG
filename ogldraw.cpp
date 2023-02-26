#include "ogldraw.h"

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

    draw_scissor_test();

    draw_alpha_test();

    draw_blend();

    if (type == "GL_POINTS")            draw(GL_POINTS);
    if (type == "GL_LINES")             draw(GL_LINES);
    if (type == "GL_LINE_STRIP")        draw(GL_LINE_STRIP);
    if (type == "GL_LINE_LOOP")         draw(GL_LINE_LOOP);
    if (type == "GL_TRIANGLES")         draw(GL_TRIANGLES);
    if (type == "GL_TRIANGLE_STRIP")    draw(GL_TRIANGLE_STRIP);
    if (type == "GL_TRIANGLE_FAN")      draw(GL_TRIANGLE_FAN);
    if (type == "GL_QUADS")             draw(GL_QUADS);
    if (type == "GL_QUAD_STRIP")        draw(GL_QUAD_STRIP);
    if (type == "GL_POLYGON")           draw(GL_POLYGON);
    if (type == "CIRCLES")              draw_circles();

    if (is_clear){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        is_clear = false;
        points.clear();
    }
}

void OGLDraw::draw(GLenum type)
{
    glPointSize(cur_point_size);
    glLineWidth(cur_line_size);
    glBegin(type);
        for (auto point: points){
            glColor4f(point.col.redF(), point.col.greenF(), point.col.blueF(), point.transparency);
            glVertex2f (point.coord.rx() * this->width() / start_width, point.coord.ry() * this->height() / start_height);
        }
    glEnd();
}

void OGLDraw::draw_scissor_test()
{
    if (is_scissor_test && rubberBand && (rubberBand->width() > 0 || rubberBand->height() > 0)){
        glEnable(GL_SCISSOR_TEST);
        glScissor(rubberBand->x() * start_width / this->width(), this->height() - (rubberBand->y() + rubberBand->height())  * start_height / this->height(),
                  rubberBand->width() * start_width / this->width(), rubberBand->height() * start_height / this->height());
    }
    else glDisable(GL_SCISSOR_TEST);
}

void OGLDraw::draw_alpha_test()
{
    if (is_alpha_test){
        glEnable(GL_ALPHA_TEST);
        if (type_alpha == "GL_NEVER") glAlphaFunc(GL_NEVER, ref_alpha);
        if (type_alpha == "GL_LESS") glAlphaFunc(GL_LESS, ref_alpha);
        if (type_alpha == "GL_EQUAL") glAlphaFunc(GL_EQUAL, ref_alpha);
        if (type_alpha == "GL_LEQUAL") glAlphaFunc(GL_LEQUAL, ref_alpha);
        if (type_alpha == "GL_GREATER") glAlphaFunc(GL_GREATER, ref_alpha);
        if (type_alpha == "GL_NOTEQUAL") glAlphaFunc(GL_NOTEQUAL, ref_alpha);
        if (type_alpha == "GL_GEQUAL") glAlphaFunc(GL_GEQUAL, ref_alpha);
        if (type_alpha == "GL_ALWAYS") glAlphaFunc(GL_ALWAYS, ref_alpha);
    }
    else glDisable(GL_ALPHA_TEST);
}

void OGLDraw::mousePressEvent(QMouseEvent* apEvent)
{
    event_point = apEvent->pos();
    if (!rubberBand)
        rubberBand = std::unique_ptr<QRubberBand>(new QRubberBand(QRubberBand::Rectangle, this));
    rubberBand->setGeometry(QRect(event_point, QSize()));
    rubberBand->show();
}

void OGLDraw::mouseMoveEvent(QMouseEvent *apEvent)
{
    rubberBand->setGeometry(QRect(event_point, apEvent->pos()).normalized());
}

void OGLDraw::mouseReleaseEvent(QMouseEvent *apEvent)
{
    rubberBand->hide();
    if (!(rubberBand->width() > 0 || rubberBand->height() > 0)){
        QPoint p = apEvent->pos();
        p.rx() = p.rx() * start_width / this->width();
        p.ry() = p.ry() * start_height / this->height();
        Point point(p, cur_color, cur_transparency);
        points.append(point);
    }
    else {
        if (!is_scissor_test)
            rubberBand = NULL;
    }
    repaint();
}

void OGLDraw::draw_circles()
{
    int triangleAmount = 40; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * M_PI;

    for (auto point: points){
        glColor4fv((GLfloat*)&point.col);
        glVertex2fv((GLfloat*)&point.coord);
        glBegin(GL_TRIANGLE_FAN);
            for(int i = 0; i <= triangleAmount;i++) {
                glColor4f(point.col.redF(), point.col.greenF(), point.col.blueF(), point.transparency);
                glVertex2f(
                    (point.coord.rx() + (cur_point_size * cos(i * twicePi / triangleAmount))) * start_width / this->width(),
                    (point.coord.ry() + (cur_point_size * sin(i * twicePi / triangleAmount))) * start_height / this->height()
                );
            }
        glEnd();
    }
}

void OGLDraw::draw_blend()
{
    if (is_blend){
        glEnable(GL_BLEND);
        glBlendFunc(sfactor_map[type_sfactor], dfactor_map[type_dfactor]);
    }
    else glDisable(GL_BLEND);
}
