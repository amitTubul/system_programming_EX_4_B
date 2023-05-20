#pragma once
#include "Team.hpp"

#define MAX_CAPACITY 10

namespace ariel{
    class Team2 : public Team{
    public:
        Team2(Character* leader);
    };
}