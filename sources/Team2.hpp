#pragma once
#include "Team.hpp"

namespace ariel{
    class Team2 : public Team{
    public:
        explicit Team2(Character* leader);
        void add(Character *teamMate) override ;
    };
}