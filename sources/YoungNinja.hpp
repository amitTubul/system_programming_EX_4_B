#pragma once
#include "Ninja.hpp"

#define Y_NINJA_SPEED 14
#define Y_NINJA_HIT_POINTS 100

namespace ariel{
    class YoungNinja : public Ninja{
    public:
        YoungNinja(std::string name,Point location);
        ~YoungNinja() override=default;
    };
}