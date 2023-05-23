#pragma once
#include "Ninja.hpp"

namespace ariel{
    class YoungNinja : public Ninja{
    private:
        static const int Y_NINJA_SPEED { 14 };
        static const int Y_NINJA_HIT_POINTS { 100 };
    public:
        YoungNinja(std::string name,Point location);
    };
}