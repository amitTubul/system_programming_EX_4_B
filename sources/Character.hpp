#pragma once
#include <string>
#include "Point.hpp"

//maybe pure virtual
namespace ariel{
    class Character{
    private:
        std::string _name;
        Point _location;
        int _hitPoints;

    public:
        Character(std::string name, Point point, int hitPoints);
        virtual ~Character()=default;
        bool isAlive();
        double distance(Character* other);
        void hit(int hitPoints);
        std::string getName();
        const Point getLocation();
        virtual std::string print() const=0;// done by children
        int getHitPoints();
        void setLocation(const Point & location);

        // for tidy check
        Character(const Character &) = delete;
        Character &operator=(const Character &) = delete;
        Character(Character &&) = delete;
        Character &operator=(Character &&) = delete;
    };
}
