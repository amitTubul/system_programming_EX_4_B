#include "Character.hpp"
using namespace std;

namespace ariel{
    Character::Character(string name, ariel::Point point, int hitPoints):_name(name),
                                                                         _location(point), _hitPoints(hitPoints){}
    bool Character::isAlive() {return _hitPoints>0;}

    double Character::distance(ariel::Character *other) {
        return _location.distance(other->getLocation());
    }

    void Character::hit(int hitPoints) {_hitPoints-=hitPoints;}

    std::string Character::getName() {return _name;}

    const Point Character::getLocation() const {return _location;}

    int Character::getHitPoints() {return _hitPoints;}

    void Character::setLocation(const Point & location) {
        this->_location=location;
    }




}
