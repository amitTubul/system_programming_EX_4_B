#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#define MAX_CAPACITY 10

namespace ariel{
    class Team{
    private:
        std::vector<Character*> _teamMates;
        Character* _leader;
        int _matesAmount;
    public:
        Team(Character* leader);
        ~Team();
        void add(Character* teamMate);
        void attack(Team* otherTeam);
        int stillAlive() const;
        void print() const;
        Character* findClosestTeamMateCharacter(Character*current, std::vector<Character*> teamMates);
        std::vector<Character*> getTeamMates();

    };
}