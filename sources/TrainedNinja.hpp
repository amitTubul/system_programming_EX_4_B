#pragma once
#include "Ninja.hpp"


namespace ariel{
    class TrainedNinja : public Ninja{
    private:
        static const int T_NINJA_SPEED { 12 };
        static const int T_NINJA_HIT_POINTS { 120 };
    public:
        TrainedNinja(std::string name,Point location);

    };
}