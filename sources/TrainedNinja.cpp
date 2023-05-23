#include "TrainedNinja.hpp"

#include <utility>

namespace ariel{
    TrainedNinja::TrainedNinja(std::string name, ariel::Point location): Ninja(std::move(name),location,T_NINJA_SPEED,T_NINJA_HIT_POINTS) {}
}