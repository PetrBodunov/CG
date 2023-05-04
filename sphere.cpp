#include "sphere.h"

Sphere::Sphere(float R,int slices, int stacks, QVector3D rotate, QVector3D shift, QVector3D scale, int angle) :
    Figure(rotate, shift, scale, angle), R(R), slices(slices), stacks(stacks)
{
    make_coords();
}


void Sphere::make_coords(){
    coord.clear();
    float drho = (float)M_PI / (float) stacks;
    float dtheta = 2.0f * (float)M_PI / (float) slices;
    float ds = 1.0f / (float) slices;
    float dt = 1.0f / (float) stacks;
    float t = 1.0f;
    float s = 0.0f;
    int i, j;

     for (i = 0; i < stacks; i++)
    {
        float rho = (float)i * drho;
        float srho = (float)(sin(rho));
        float crho = (float)(cos(rho));
        float srhodrho = (float)(sin(rho + drho));
        float crhodrho = (float)(cos(rho + drho));

        s = 0.0f;
        for ( j = 0; j <= slices; j++)
        {
            float theta = (j == slices) ? 0.0f : j * dtheta;
            float stheta = (float)(-sin(theta));
            float ctheta = (float)(cos(theta));

            float x = stheta * srho;
            float y = ctheta * srho;
            float z = crho;

            coord.push_back(QVector3D(x * R, y * R, z * R));
            x = stheta * srhodrho;
            y = ctheta * srhodrho;
            z = crhodrho;
            s += ds;
            coord.push_back(QVector3D(x * R, y * R, z * R));
        }
        t -= dt;
    }
}
