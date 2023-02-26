#ifndef POINT_H
#define POINT_H

#include <QPoint>
#include <QColor>

class Point
{
public:
    QPoint coord;
    QColor col;
    float transparency;

    Point(QPoint coord, QColor col, float transparency);
};

#endif // POINT_H
