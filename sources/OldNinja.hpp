#pragma once
#include "Ninja.hpp"

#define O_NINJA_SPEED 8
#define O_NINJA_HIT_POINTS 150

namespace ariel{
    class OldNinja : public Ninja{
    public:
        OldNinja(std::string name,Point location);
        ~OldNinja() override=default;
    };
}