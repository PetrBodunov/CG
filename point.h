#ifndef POINT_H
#define POINT_H

#include <QPoint>
#include <QColor>

class Point
{
public:
    QPoint coord;
    QColor col;

    Point(QPoint coord, QColor col);
};

#endif // POINT_H
