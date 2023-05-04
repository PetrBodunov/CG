#ifndef CUBE_H
#define CUBE_H

#include "figure.h"

class Cube : public Figure
{
public:
    Cube(float a, QVector3D rotate, QVector3D shift, QVector3D scale, int angle = 0);

    float a;
    void make_coords();
};

#endif // CUBE_H
