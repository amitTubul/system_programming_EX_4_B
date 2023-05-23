#pragma once
#include "Ninja.hpp"


namespace ariel{
    class OldNinja : public Ninja{
        static const int O_NINJA_SPEED { 8 };
        static const int O_NINJA_HIT_POINTS { 150 };
    public:
        OldNinja(std::string name,Point location);
    };
}