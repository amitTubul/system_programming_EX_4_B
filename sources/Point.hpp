#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>

namespace ariel{

    class Point{
    private:
        double _x,_y;

    public:
        Point(double xCordinate, double yCordinate);
        double distance(const Point& other) const;
        std::string print() const;
        static Point moveTowards(const Point& source, const Point& dest, double maxDistance);
        double getX() const;
        double getY() const;
    };

}

