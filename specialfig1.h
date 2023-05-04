#ifndef SPECIALFIG1_H
#define SPECIALFIG1_H

#include "figure.h"

class SpecialFig1 : public Figure
{
public:
    float R;
    float r_in;
    int slices;
    int stacks;

    SpecialFig1(float R, float r_in, int slices, int stacks, QVector3D rotate, QVector3D shift, QVector3D scale, int angle=0);

    void make_coords();
};

#endif // SPHERE_H
