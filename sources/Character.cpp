#include "Character.hpp"

#include <utility>
using namespace std;

namespace ariel{
    Character::Character(string name, ariel::Point point, int hitPoints):_name(std::move(name)),
                                                                         _location(point),
                                                                         _hitPoints(hitPoints),_isInGame(false){}
    bool Character::isAlive() const {return _hitPoints>0;}

    double Character::distance(ariel::Character *other) {
        return _location.distance(other->getLocation());
    }

    void Character::hit(int hitPoints) {
        if(hitPoints<0)throw invalid_argument("cannot hit negative hit points");
        _hitPoints -= hitPoints;
    }

    std::string Character::getName() const {return _name;}

    Point Character::getLocation() const {return _location;}

    int Character::getHitPoints() const {return _hitPoints;}

    void Character::setLocation(const Point & location) {
        this->_location=location;
    }

    void Character::setPlaying(bool condition) {_isInGame=condition;}

    bool Character::isPlaying() const {return _isInGame;}


}
