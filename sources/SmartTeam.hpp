#pragma once
#include "Team.hpp"

#define MAX_CAPACITY 10

namespace ariel{
    class SmartTeam : public Team{
    public:
        SmartTeam(Character* leader);
    };
}