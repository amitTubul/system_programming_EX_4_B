#include "Team2.hpp"
namespace ariel{
    Team2::Team2(ariel::Character *leader): Team(leader) {}

    void Team2::add(ariel::Character *teamMate) {
        if (getTeamMates().size() >= MAX_CAPACITY) {
            throw std::runtime_error("Team is already at max capacity");
        }
        if(teamMate->isPlaying()){
            throw std::runtime_error("character is already playing");
        }
        addToTeamMates(teamMate);
    }

    
}