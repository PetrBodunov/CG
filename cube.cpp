#include "cube.h"

Cube::Cube(float a, QVector3D rotate, QVector3D shift, QVector3D scale, int angle):
    a(a), Figure(rotate, shift, scale, angle)
{
    make_coords();
}


void Cube::make_coords(){
    coord.clear();
    coord = {QVector3D(-a/2, a/2, a/2), QVector3D(a/2, a/2, a/2), QVector3D(a/2, -a/2, a/2), QVector3D(-a/2, -a/2, a/2),
             QVector3D(-a/2, a/2, a/2), QVector3D(-a/2, -a/2, a/2), QVector3D(-a/2, -a/2, -a/2), QVector3D(-a/2, a/2, -a/2),
             QVector3D(a/2, a/2, a/2), QVector3D(a/2, -a/2, a/2), QVector3D(a/2, -a/2, -a/2), QVector3D(a/2, a/2, -a/2),
             QVector3D(-a/2, a/2, -a/2), QVector3D(a/2, a/2, -a/2), QVector3D(a/2, -a/2, -a/2), QVector3D(-a/2, -a/2, -a/2),
             QVector3D(-a/2, a/2, a/2), QVector3D(-a/2, a/2, -a/2), QVector3D(a/2, a/2, -a/2), QVector3D(a/2, a/2, a/2),
             QVector3D(-a/2, -a/2, a/2), QVector3D(-a/2, -a/2, -a/2), QVector3D(a/2, -a/2, -a/2), QVector3D(-a/2, -a/2, -a/2)};
}
