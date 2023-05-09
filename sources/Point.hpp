#ifndef POINT_HPP
#define POINT_HPP
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;

    public:
        Point();

        Point(double point_x, double point_y);

        double getPointX() const;

        double getPointY() const;

        double distance(const Point &point) const;

        void print() const;

        Point moveTowards(const Point &destanation, double distance);
    };
};

#endif