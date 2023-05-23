#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel{
    class Team{
    private:
        std::vector<Character*> _teamMates;
        Character* _leader;
    public:
        explicit Team(Character* leader);
        virtual ~Team();

        virtual void add(Character* teamMate);
        virtual void attack(Team* otherTeam);
        int stillAlive() const;
        void print() const;
        static Character* findClosestTeamMateCharacter(Character*current, const std::vector<Character*>& teamMates);

        std::vector<Character*> getTeamMates();
        void addToTeamMates(Character* teamMate);
        Character* getLeader();

        // for tidy check
        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;

        static const int MAX_CAPACITY { 10 };
    };
}