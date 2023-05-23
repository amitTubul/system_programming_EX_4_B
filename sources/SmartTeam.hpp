#pragma once
#include "Team.hpp"


namespace ariel{
    class SmartTeam : public Team{
    public:
        explicit SmartTeam(Character* leader);
        void add(ariel::Character *teamMate) override;
        void attack(ariel::Team *otherTeam) override;
        static Character* findClosestWeakestVictim(Character*current, const std::vector<Character*>& teamMates);
    };
}