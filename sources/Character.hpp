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
        bool _isInGame;

    public:
        Character(std::string name, Point point, int hitPoints);
        virtual ~Character() = default;
        bool isAlive() const;
        double distance(Character* other);
        void hit(int hitPoints);
        std::string getName() const;
        virtual std::string print() const=0;// done by children
        int getHitPoints() const;
        Point getLocation() const;
        void setLocation(const Point & location);
        void setPlaying(bool condition);
        bool isPlaying() const;
        // for tidy check
        Character(const Character &) = delete;
        Character &operator=(const Character &) = delete;
        Character(Character &&) = delete;
        Character &operator=(Character &&) = delete;
    };
}
