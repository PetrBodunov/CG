#include "specialfig2.h"

SpecialFig2::SpecialFig2(float h, float r, int slices, int stacks, QVector3D rotate, QVector3D shift, QVector3D scale, int angle):
    Figure(rotate, shift, scale, angle), h(h), r(r), slices(slices), stacks(stacks)
{
    make_coords();
}

void SpecialFig2::make_coords()
{
    coord.clear();

    float dtheta = 2.0f * (float)M_PI / (float) stacks;
    float dy = (float)h / slices;
    float dr = (float)r / slices;

    for (int j = 0; j < slices; j++){
        for (int i = 0; i < stacks; i++)
        {
            float y =  -(float)h / 2 + j * dy;

            float x = (r - j * dr) * cos((float)i * dtheta);
            float z = (r - j * dr) * sin((float)i * dtheta);

            float x1 = (r - (j + 1) * dr) * cos((float)i * dtheta);
            float z1 = (r - (j + 1) * dr) * sin((float)i * dtheta);

            float x2 = (r - j * dr) * cos((float)(i + 1) * dtheta);
            float z2 = (r - j * dr) * sin((float)(i + 1) * dtheta);

            float x3 = (r - (j + 1) * dr) * cos((float)(i + 1) * dtheta);
            float z3 = (r - (j + 1) * dr) * sin((float)(i + 1) * dtheta);

            coord.push_back(QVector3D(x, y, z));
            coord.push_back(QVector3D(x, y + dy, z));
            coord.push_back(QVector3D(x1, y + dy, z1));
            coord.push_back(QVector3D(x1, y, z1));

            coord.push_back(QVector3D(x, y, z));
            coord.push_back(QVector3D(x2, y, z2));
            coord.push_back(QVector3D(x2, y + dy, z2));
            coord.push_back(QVector3D(x, y + dy, z));

            coord.push_back(QVector3D(x2, y, z2));
            coord.push_back(QVector3D(x2, y + dy, z2));
            coord.push_back(QVector3D(x3, y + dy, z3));
            coord.push_back(QVector3D(x3, y, z3));

            coord.push_back(QVector3D(x1, y, z1));
            coord.push_back(QVector3D(x1, y + dy, z1));
            coord.push_back(QVector3D(x3, y + dy, z3));
            coord.push_back(QVector3D(x3, y, z3));

            coord.push_back(QVector3D(x, y, z));
            coord.push_back(QVector3D(x1, y, z1));
            coord.push_back(QVector3D(x3, y, z3));
            coord.push_back(QVector3D(x2, y, z2));

            coord.push_back(QVector3D(x, y + dy, z));
            coord.push_back(QVector3D(x1, y + dy, z1));
            coord.push_back(QVector3D(x3, y + dy, z3));
            coord.push_back(QVector3D(x2, y + dy, z2));
        }
    }
}
