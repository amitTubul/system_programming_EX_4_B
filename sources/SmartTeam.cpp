#include "SmartTeam.hpp"

namespace ariel{
    SmartTeam::SmartTeam(ariel::Character *leader) : Team(leader){}

    // insert ninjas at first position
    void SmartTeam::add(ariel::Character *teamMate) {
        std::vector<Character*>teamMates=getTeamMates();
        if (teamMates.size() >= MAX_CAPACITY) {
            throw std::runtime_error("Team is already at max capacity");
        }
        if(teamMate->isPlaying()){
            throw std::runtime_error("character is already playing");
        }

        auto insertPosition = teamMates.end();
        for (auto it = teamMates.begin(); it != teamMates.end(); ++it) {
            if (!dynamic_cast<Ninja *>(*it)) {
                insertPosition = it;
                break;
            }
        }
        teamMates.insert(insertPosition, teamMate);
    }

    void SmartTeam::attack(ariel::Team *otherTeam) {
        Character* leader=getLeader();
        std::vector<Character *> teamMates=getTeamMates();

        if (!leader->isAlive()) {
            leader = findClosestTeamMateCharacter(leader, teamMates);
        }

        Character *victim = findClosestWeakestVictim(leader, teamMates);
        for (Character *member: teamMates) {
            if (!member->isAlive()) continue;
            if (otherTeam->stillAlive() == 0) return;

            auto *cowboyPtr = dynamic_cast<Cowboy *>(member);
            if (cowboyPtr) {
                if (!cowboyPtr->hasboolets()) cowboyPtr->reload();
                cowboyPtr->shoot(victim);
            } else {
                auto *ninjaPtr = dynamic_cast<Ninja *>(member);
                if (ninjaPtr->distance(victim) <= 1) {
                    ninjaPtr->slash(victim);
                } else {
                    ninjaPtr->move(victim);
                }
            }
            if (!victim->isAlive()) {
                victim = findClosestWeakestVictim(leader, otherTeam->getTeamMates());
                if (!victim) return;
            }
        }
    }

    // finding the weakest
    Character *SmartTeam::findClosestWeakestVictim(Character *current, const std::vector<Character *> &teamMates) {
        double minDistance = (double)INTMAX_MAX;
        long hitPoints = INTMAX_MAX;
        Character *character= nullptr;
        for (Character *member: teamMates) {
            if (!member->isAlive() || member==current) continue;
            double current_distance = current->distance(member);
            if (current_distance < minDistance && member->getHitPoints()<hitPoints) {
                minDistance = current_distance;
                hitPoints=member->getHitPoints();
                character = member;
            }
        }
        return character;
    }

}