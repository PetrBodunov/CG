#ifndef SPHERE_H
#define SPHERE_H

#include "figure.h"

class Sphere : public Figure
{
public:
    double R;
    int slices;
    int stacks;

    Sphere(float R,int slices, int stacks, QVector3D rotate, QVector3D shift, QVector3D scale, int angle=0);

    void make_coords();
};

#endif // SPHERE_H
