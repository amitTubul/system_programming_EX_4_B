#include "Point.hpp"

using namespace std;
namespace ariel{
    Point::Point(double xCordinate, double yCordinate):_x(xCordinate),_y(yCordinate) {}

    double Point::distance(const Point& other) const{
        return sqrt(pow(this->_x-other.getX(),2)+pow(this->_y-other.getY(),2));
    }

    string Point::print() const {
        return "("+ to_string(_x)+","+ to_string(_y) + ")";
    }

    Point Point::moveTowards(const Point& source, const Point& dest, double maxDistance) {
        if (maxDistance < 0) {
            throw invalid_argument("negative distance is forbidden");
        }
        double distance = source.distance(dest);
        if (distance <= maxDistance) return dest;
        // else
        double ratio = maxDistance / distance;
        double dx = dest._x - source._x;
        double dy = dest._y - source._y;
        return {source._x + dx * ratio, source._y + dy * ratio};
    }

    double Point::getX() const {return _x;}

    double Point::getY() const {return _y;}

}