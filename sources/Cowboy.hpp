#pragma once
#include "Character.hpp"


namespace ariel{
    class Cowboy : public Character{
    private:
        int _bulletAmount;

    public:
        Cowboy(std::string name,Point location);
        ~Cowboy() override=default;
        void shoot(Character* other);
        bool hasboolets();
        void reload();
        int getNumOfBullets();

    };
}