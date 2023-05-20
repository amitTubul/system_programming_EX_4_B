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
        double distance(Point other);
        std::string print();
        Point moveTowards(Point source, Point dest, double maxDistance);
        double getX();
        double getY();
    };

}

