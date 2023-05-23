#pragma once
#include "Character.hpp"

namespace ariel{
    class Ninja : public Character{
    private:
        int _speed;

    public:
        Ninja(std::string name,Point location, int speed, int hitPoints);
        ~Ninja() override=default;
        void move(Character* other);
        void slash(Character* other);
        std::string print() const override;
        // for tidy check
        Ninja(const Ninja&) = delete;
        Ninja& operator=(const Ninja&) = delete;
        Ninja(Ninja&&) = delete;
        Ninja& operator=(Ninja&&) = delete;
    };
}