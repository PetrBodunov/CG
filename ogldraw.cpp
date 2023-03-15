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
    x0 = this->width() / 2;
    y0 = this->height() / 2;
    qDebug() << "x0 " << x0 << " y0 " << y0;
}

void OGLDraw::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    for (auto p: points)
//        qDebug() << "coord: " << p.coord;
//    qDebug() << "--------------------------";

    draw();
}

void OGLDraw::draw()
{
    glPointSize(cur_point_size);
    glLineWidth(cur_line_size);
    glScalef(rotate_x, rotate_x, 1);

    glBegin(GL_LINES);
    for (auto p1: points){
        for (auto p2: points){
            glColor3f(p1.col.redF(), p1.col.greenF(), p1.col.blueF());
            glVertex2f (p1.coord.rx() * this->width() / start_width, p1.coord.ry() * this->height() / start_height);

            glColor3f(p2.col.redF(), p2.col.greenF(), p2.col.blueF());
            glVertex2f (p2.coord.rx() * this->width() / start_width, p2.coord.ry() * this->height() / start_height);
        }
    }
    glEnd();

    draw_circles();

}


void OGLDraw::draw_circles()
{
    int pointAmount = 60; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * M_PI;

    for (auto point: points){
        glColor3fv((GLfloat*)&point.col);
        glVertex2fv((GLfloat*)&point.coord);
        glBegin(GL_LINE_LOOP);
            for(int i = 0; i <= pointAmount;i++) {
                glColor3f(point.col.redF(), point.col.greenF(), point.col.blueF());
                glVertex2f(
                    (point.coord.rx() + (r / 2 * cos(i * twicePi / pointAmount))) * this->width() / start_width,
                    (point.coord.ry() + (r / 2 * sin(i * twicePi / pointAmount))) * this->height() / start_height
                );
            }
        glEnd();
    }
}

void OGLDraw::make_points()
{
    srand((unsigned) time(NULL));

    qDebug() << "kek " << iter;

    for (int j = 0; j < iter; j++){
        int cur_r = r * pow(2, j);
        for (int i = 0; i < c_p; i++){
            QPoint p(x0 * start_width / this->width() + cur_r * cos(2 * M_PI * i / c_p + M_PI / 2),
                     y0 * start_height / this->height() + cur_r * sin(2 * M_PI * i / c_p  + M_PI / 2));
            QColor col(std::rand() % 255, std::rand() % 255, std::rand() % 255);
            Point point(p, col);
            points.append(point);
        }
    }
}

void OGLDraw::change_points_coord(){
    for (int j = 0; j < iter; j++){
        int cur_r = r * pow(2, j);
        for (int i = c_p * j; i < c_p * (j + 1); i++){
            QPoint p(x0 * start_width / this->width() + cur_r * cos(2 * M_PI * i / c_p + M_PI / 2),
                     y0 * start_height / this->height() + cur_r * sin(2 * M_PI * i / c_p  + M_PI / 2));
            points[i].coord = p;
        }
    }
}

void OGLDraw::wheelEvent(QWheelEvent *event)
{
    QPoint nAngle = event->angleDelta();
    QPoint nPixels = event->pixelDelta();
    if (!nAngle.isNull()){
        qDebug() << "wheel";
        if (event->angleDelta().y() > 0)
        {
            qDebug() << "zoom in";
            r += 4;
            change_points_coord();
            repaint();
            return;
        }

        else if(event->angleDelta().y() < 0)
        {
            qDebug() << "zoom out";
            r -= 4;
            change_points_coord();
            repaint();
            return;
        }
    }
//    else if (!nPixels.isNull()){
//        qDebug() << "touchpad";
//        glScalef(1.002,1.002,1);
//    }
//    bool controlKeyIsHeld = QGuiApplication::keyboardModifiers().testFlag(Qt::ControlModifier);

//    // If vertical mouse wheel goes up, then zoom in.
//    if(event->angleDelta().y() > 0 && controlKeyIsHeld)
//    {
//        this->zoomIn(1);
//        return;
//    }

//    else if(event->angleDelta().y() < 0 && controlKeyIsHeld)
//    {
//        this->zoomOut(1);
//        return;
//    }

//    QTextEdit::wheelEvent(event);
}
