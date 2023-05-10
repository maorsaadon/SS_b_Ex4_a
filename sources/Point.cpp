#include <stdio.h>
#include <cmath>
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    Point::Point() : _x(0), _y(0) {}

    Point::Point(double _x, double _y) : _x(_x), _y(_y) {}

    double Point::getPointX() const
    {
        return _x;
    }

    double Point::getPointY() const
    {
        return _y;
    }

    double Point::distance(const Point &point) const
    {
        return sqrt(pow(point._x - _x, 2) + pow(point._y - _y, 2));
    }

    void Point::print() const
    {
        cout << "(" << _x << "," << _y << ")" << endl;
    }

    Point Point::moveTowards(const Point &destination, double distance) const
    {
        if (distance == 0)
            return *this;
        else if (distance >= Point::distance(destination))
            return destination;
        else
        {
            double ratio_dist = distance / Point::distance(destination);
            return Point((1 - ratio_dist) * _x + (ratio_dist)*destination._x, (1 - ratio_dist) * _y + (ratio_dist)*destination._y);
        }
    }

}
