#include "Cowboy.hpp"
using namespace std;

namespace ariel{
    Cowboy::Cowboy(std::string name, ariel::Point location): Character(name,location,110) {
        _bulletAmount=6;

    }

    void Cowboy::shoot(ariel::Character *other) {
        if (!this->isAlive() || !other->isAlive())throw runtime_error("one of the characters is already dead");
        if (this == other) throw runtime_error("Cowboy cannot shoot himself");
        if (this->isAlive() && _bullets > 0) {
            --_bullets;
            other->hit(10);
        }
    }

    bool Cowboy::hasboolets() {return _bulletAmount>0;}

    void Cowboy::reload() {_bulletAmount=6;}

    std::string Character::print() const{
        string str = "C : ";
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

    int Cowboy::getNumOfBullets() {return _bulletAmount;}
}