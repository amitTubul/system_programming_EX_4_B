#include "Ninja.hpp"

#include <utility>
using namespace std;

namespace ariel{
    Ninja::Ninja(string name, Point location, int speed, int hitPoints):
    Character(std::move(name),location,hitPoints),_speed(speed) {}

    void Ninja::move(Character *other) {
        if (!isAlive()) {
            throw runtime_error("dead character cannot move.");
        }

        const Point& myLocation = getLocation();
        const Point& otherLocation = other->getLocation();

        double distance = myLocation.distance(otherLocation);
        double maxDistance = _speed;

        if (distance <= maxDistance) {
            setLocation(otherLocation);
        } else {
            Point new_location = Point::moveTowards(myLocation, otherLocation, maxDistance);
            setLocation(new_location);
        }
    }

    void Ninja::slash(Character *other) {
        if (!isAlive() || !other->isAlive()) throw runtime_error("one of the characters is already dead");
        if (this == other) throw runtime_error("Ninja cannot slash himself");
        const Point myLocation = getLocation();
        const Point otherLocation = other->getLocation();

        double distance = myLocation.distance(otherLocation);
        if (distance <= 1) {
            other->hit(40);
        }
    }

    string Ninja::print() const {
        string str = "N : ";
        if (!isAlive()) {
            str += "Name: (" + getName() + "), Location:" +
                getLocation().print()
                + '\n';
        } else {
            str += "Name: " + getName() + ", Hit Points:" + " (" + to_string(getHitPoints()) + ") " + ", Location: " +
                getLocation().print() + '\n';
        }
        return str;
    }

}