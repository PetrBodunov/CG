#ifndef SPECIALFIG2_H
#define SPECIALFIG2_H

#include "figure.h"
#include <math.h>

class SpecialFig2 : public Figure
{
public:
    float h;
    float r;
    int slices;
    int stacks;

    SpecialFig2(float h, float r, int slices, int stacks, QVector3D rotate, QVector3D shift, QVector3D scale, int angle=0);

    void make_coords();
};

#endif // SPECIALFIG2_H
