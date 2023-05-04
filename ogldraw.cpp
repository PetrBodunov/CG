#include "ogldraw.h"

OGLDraw::OGLDraw(QWidget* pwgt) : QOpenGLWidget(pwgt)
{
    grabKeyboard();
}

OGLDraw::~OGLDraw()
{
    delete s;
    delete c;
    delete sf1;
    delete sf2;
}

void OGLDraw::initializeGL()
{
    initializeOpenGLFunctions();
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0, 0, 0, 1.0f);

    start_width = this->width();
    start_height = this->height();
}

void OGLDraw::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(0, nWidth, nHeight, 0, -1, 1);
//    glViewport (0, 0, (GLint)nWidth, (GLint)nHeight);

}

void OGLDraw::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    moveCamera();
    draw_coordinate_system();
    draw_cube(c, QColor(0,255,255));
    draw_sphere(s, QColor(255,0,255));
    draw_specialfig1(sf1, QColor(200,200,200));
    draw_specialfig2(sf2, QColor(255,255,0));

    glPopMatrix();


}

void OGLDraw::draw_coordinate_system()
{
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(1, 0, 0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 1, 0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 0, 1);
    glEnd();
}


//void OGLDraw::showWorld()
//{
//    float vert[] = {1,1,0, 1,-1,0, -1,-1,0, -1,1,0};
//    glEnableClientState(GL_VERTEX_ARRAY);
//        glVertexPointer(3, GL_FLOAT, 0, &vert);
//        glColor3f(0,0.5,0);
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//    glDisableClientState(GL_VERTEX_ARRAY);
//}


void OGLDraw::moveCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)start_width / start_height, 0.1, 400.0);
    float R = sqrt(xed * xed + zed * zed);
    xev = xed * cos(angley * M_PI / 180);
    yev = R * sin(angley * M_PI / 180);
    zev = zed * cos(angley * M_PI / 180);


    gluLookAt(xe, ye, ze, xe + xev, ye + yev, ze + zev, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OGLDraw::keyPressEvent(QKeyEvent *ev)
{
    float xt;
    switch(ev->key()){
        case Qt::Key_W:
            xe += xev;
            ye += yev;
            ze += zev;
            break;

        case Qt::Key_A:
            xe -= 0.02;
            break;

        case Qt::Key_S:
            xe -= xev;
            ye -= yev;
            ze -= zev;
            break;

        case Qt::Key_D:
            xe += 0.02;
            break;

        case Qt::Key_Space:
            ye += 0.05;
            break;

        case Qt::Key_Shift:
            ye -= 0.05;
            break;

        case Qt::Key_Up:
            angley += 2;
            break;

        case Qt::Key_Down:
            angley -= 2;
            break;

        case Qt::Key_Left:
            xt = xed;
            xed = xed * cos(-2 * M_PI / 180) - zed * sin(-2 * M_PI / 180);
            zed = xt * sin(-2 * M_PI / 180) + zed * cos(-2 * M_PI / 180);
            break;

        case Qt::Key_Right:
            xt = xed;
            xed = xed * cos(2 * M_PI / 180) - zed * sin(2 * M_PI / 180);
            zed = xt * sin(2 * M_PI / 180) + zed * cos(2 * M_PI / 180);
            break;

        default:
            break;
    }

    repaint();
}


void OGLDraw::draw_cube(Cube* objectmodel, QColor color){
    glPushMatrix();
    glScalef(objectmodel->scale.x(),objectmodel->scale.y(),objectmodel->scale.z());
    glRotatef(objectmodel->angle,objectmodel->rotate.x(),objectmodel->rotate.y(),objectmodel->rotate.z());
    glTranslatef(objectmodel->shift.x(),objectmodel->shift.y(),objectmodel->shift.z());

    glColor3ub(color.red(),color.green(),color.blue());


    glBegin(GL_QUADS);
    for (int i = 0;i < objectmodel->coord.size();i++) {
        glVertex3d(objectmodel->coord[i].x(), objectmodel->coord[i].y(), objectmodel->coord[i].z());
     }
    glEnd();

    glPopMatrix();

}


void OGLDraw::draw_sphere(Sphere* objectmodel, QColor color)
{
    glPushMatrix();
    glRotatef(objectmodel->angle,objectmodel->rotate.x(),objectmodel->rotate.y(),objectmodel->rotate.z());
    glTranslatef(objectmodel->shift.x(),objectmodel->shift.y(),objectmodel->shift.z());
    glScalef(objectmodel->scale.x(),objectmodel->scale.y(),objectmodel->scale.z());
    glColor3ub(color.red(),color.green(),color.blue());

    glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0;i < objectmodel->coord.size();i++) {
            glVertex3d(objectmodel->coord[i].x(), objectmodel->coord[i].y(), objectmodel->coord[i].z());
        }
    glEnd();

    glPopMatrix();
}


void OGLDraw::draw_specialfig1(SpecialFig1* objectmodel, QColor color)
{
    glPushMatrix();
    glRotatef(objectmodel->angle,objectmodel->rotate.x(),objectmodel->rotate.y(),objectmodel->rotate.z());
    glTranslatef(objectmodel->shift.x(),objectmodel->shift.y(),objectmodel->shift.z());
    glScalef(objectmodel->scale.x(),objectmodel->scale.y(),objectmodel->scale.z());
    glColor3ub(color.red(),color.green(),color.blue());

    glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0;i < objectmodel->coord.size();i++) {
            glVertex3d(objectmodel->coord[i].x(), objectmodel->coord[i].y(), objectmodel->coord[i].z());
        }
    glEnd();

    glPopMatrix();
}


void OGLDraw::draw_specialfig2(SpecialFig2* objectmodel, QColor color){
    glPushMatrix();
    glRotatef(objectmodel->angle,objectmodel->rotate.x(),objectmodel->rotate.y(),objectmodel->rotate.z());
    glTranslatef(objectmodel->shift.x(),objectmodel->shift.y(),objectmodel->shift.z());
    glScalef(objectmodel->scale.x(),objectmodel->scale.y(),objectmodel->scale.z());
    glColor3ub(color.red(),color.green(),color.blue());

    glBegin(GL_QUADS);
    for (int i = 0;i < objectmodel->coord.size();i++) {
        glVertex3d(objectmodel->coord[i].x(), objectmodel->coord[i].y(), objectmodel->coord[i].z());
    }
    glEnd();
    glPopMatrix();
}
