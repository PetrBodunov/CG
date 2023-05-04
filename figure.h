#ifndef FIGURE_H
#define FIGURE_H

#include <QVector3D>
#include <QVector>

class Figure
{
public:
    Figure(QVector3D rotate, QVector3D shift, QVector3D scale, int angle = 0);


    QVector<QVector3D> coord;
    QVector3D rotate;
    QVector3D shift;
    QVector3D scale;
    int angle;
};

#endif // FIGURE_H
