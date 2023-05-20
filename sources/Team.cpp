#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    Team::Team(Character *leader) : _leader(leader), _matesAmount(0) {
        add(leader);
    }

    Team::~Team() {
        for (Character *member: _teamMates)delete (member);
    }

    void Team::add(Character *teamMate) {
        if (_teamMates.size() >= MAX_CAPACITY) {
            throw std::runtime_error("Team is already at max capacity");
        }

        auto insertPosition = _teamMates.end();
        if (dynamic_cast<Cowboy *>(teamMate)) {
            for (auto it = _teamMates.begin(); it != _teamMates.end(); ++it) {
                if (!dynamic_cast<Cowboy *>(*it)) {
                    insertPosition = it;
                    break;
                }
            }
        }
        _teamMates.insert(insertPosition, member);
    }

    void Team::attack(ariel::Team *otherTeam) {
        if (!_leader->isAlive()) {
            findClosestTeamMateCharacter(_leader, _teamMates);
        }

        Character *victim = findClosestTeamMateCharacter(_leader, otherTeam.getTeamMates());
        for (Character *member: _teamMates) {
            Cowboy *cowboyPtr = dynamic_cast<Cowboy *>(Character);
            if (cowboyPtr) {
                if (!cowboyPtr->hasboolets())cowboyPtr->reload();
                cowboyPtr->shoot(victim);
            } else {
                Ninja *ninjaPtr = dynamic_cast<Ninja *>(Character);
                if (ninjaPtr->distance(victim) <= 1) {
                    ninjaPtr->slash(victim);
                } else {
                    ninjaPtr->move(victim);
                }
            }
            if (!victim->isAlive()) {
                victim = findClosestTeamMateCharacter(_leader, otherTeam->getTeamMates());
                if (!victim) return;
            }

        }
    }
    int Team::stillAlive() const {
        int i = 0;
        for (Character *teamMate: _teamMates ) {
            if (teamMate->isAlive()) {
                i++;
            }
        }
        return i;
    }

    void Team::print() const {
        for (Character *teamMates: _teamMates) {
            cout << teamMates->print() << endl;
        }
    }


    Character *Team::findClosestTeamMateCharacter(ariel::Character *current, std::vector<Character *> teamMates) {
        int minDistance = 0;
        Character *character;
        for (Character *member: teamMates) {
            if (!member->isAlive()) continue;
            double current_distance = current->distance(member);
            if (current_distance < minDistance) {
                character = member;
                minDistance = current_distance
            }
        }
        return character;
    }

    std::vector<Character *> Team::getTeamMates() {return _teamMates;}
}