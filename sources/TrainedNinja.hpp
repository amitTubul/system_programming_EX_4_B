#pragma once
#include "Ninja.hpp"

#define T_NINJA_SPEED 12
#define T_NINJA_HIT_POINTS 120

namespace ariel{
    class TrainedNinja : public Ninja{
    public:
        TrainedNinja(std::string name,Point location);
        ~TrainedNinja() override=default;
    };
}