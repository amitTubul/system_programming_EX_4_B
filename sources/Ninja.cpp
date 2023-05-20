#include "Ninja.hpp"
using namespace std;

namespace ariel{
    Ninja::Ninja(string name, Point location, int speed, int hitPoints): Character(name,location,hitPoints) {
        _speed=speed;
    }

    void Ninja::move(Character *other) {
        if (!isAlive()) {
            throw runtime_error("dead character cannot move.");
        }

        Point myLocation = getLocation();
        const Point otherLocation = other->getLocation();

        double distance = current_location.distance(myLocation);
        double maxDistance = _speed;

        if (distance <= maxDistance) {
            setLocation(enemy_location);
        } else {
            Point new_location = Point::moveTowards(myLocation, otherLocation, maxDistance);
            setLocation(new_location);
        }
    }

    void Ninja::slash(Character *other) {
        if (!isAlive() || !other->isAlive()) throw runtime_error("one of the characters is already dead");
        if (this == enemy) throw runtime_error("Ninja cannot slash himself");
        Point myLocation = getLocation();
        Point otherLocation = enemy->getLocation();

        double distance = current_location.distance(enemy_location);
        if (distance <= 1) {
            enemy->hit(40);
    }

    int Ninja::getSpeed() {return _speed;}

    string Character::print() const {
        string str = "N : ";
        if (!isAlive()) {
            str << "Name: (" << getName() << "), Location:" <<
                getLocation().print()
                << '\n';
        } else {
            str << "Name: " << getName() << ", Hit Points:" << " (" << _hitPoints << ") " << ", Location: " <<
                getLocation().print() << '\n';
        }
        return str;
    }

}