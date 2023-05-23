#include "Team.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    Team::Team(Character *leader) : _leader(leader) {
        add(_leader);
    }

    Team::~Team() {
        for (Character *member: _teamMates) delete (member);
    }


    void Team::add(Character *teamMate) {
        if (_teamMates.size() >= MAX_CAPACITY) {
            throw std::runtime_error("Team is already at max capacity");
        }
        if(teamMate->isPlaying()){
            throw std::runtime_error("character is already playing");
        }

        auto insertPosition = _teamMates.end();
        for (auto it = _teamMates.begin(); it != _teamMates.end(); ++it) {
            if (!dynamic_cast<Cowboy *>(*it)) {
                insertPosition = it;
                break;
            }
        }
        _teamMates.insert(insertPosition, teamMate);
        teamMate->setPlaying(true);
    }

    void Team::attack(ariel::Team *otherTeam) {
        if(otherTeam == nullptr)throw invalid_argument("cannot attack null team");

        if(otherTeam->stillAlive()==0) throw runtime_error("no one to attack, team is dead");

        if(stillAlive() == 0) return;

        if (!_leader->isAlive()) {
            _leader = findClosestTeamMateCharacter(_leader, _teamMates);
        }
        Character *victim = findClosestTeamMateCharacter(_leader, otherTeam->getTeamMates());
        for (Character *member: _teamMates) {
            if (!member->isAlive()) continue;
            if (otherTeam->stillAlive() == 0) return;

            auto *cowboyPtr = dynamic_cast<Cowboy *>(member);
            if (cowboyPtr) {
                if (!cowboyPtr->hasboolets()){
                    cowboyPtr->reload();
                    continue;
                }
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


    Character* Team::findClosestTeamMateCharacter(ariel::Character *current, const std::vector<Character *>& teamMates) {
        double minDistance = (double)INTMAX_MAX;
        Character *character= nullptr;
        for (Character *member: teamMates) {
            if (!member->isAlive() || member==current) continue;
            double current_distance = current->distance(member);
            if (current_distance < minDistance) {
                character = member;
                minDistance = current_distance;
            }
        }
        return character;
    }

    std::vector<Character *>Team::getTeamMates() {return _teamMates;}

    void Team::addToTeamMates(ariel::Character *teamMate) {
        _teamMates.push_back(teamMate);
    }

    Character *Team::getLeader() {return _leader;}
}