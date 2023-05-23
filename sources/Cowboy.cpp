#include "Cowboy.hpp"

#include <utility>
using namespace std;

namespace ariel{
    Cowboy::Cowboy(std::string name, ariel::Point location): Character(std::move(name),location,110),_bulletAmount(6) {}

    void Cowboy::shoot(ariel::Character *other) {
        if (!this->isAlive() || !other->isAlive())throw runtime_error("one of the characters is already dead");
        if (this == other) throw runtime_error("Cowboy cannot shoot himself");
        if (this->isAlive() && _bulletAmount > 0) {
            --_bulletAmount;
            other->hit(10);
        }
    }

    bool Cowboy::hasboolets() const {return _bulletAmount>0;}

    void Cowboy::reload() {
        if(!this->isAlive())throw runtime_error("dead cowboy cannot reload");
        _bulletAmount=6;
    }

    string Cowboy::print() const{
        string str = "C : ";
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