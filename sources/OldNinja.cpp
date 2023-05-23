#include "OldNinja.hpp"

#include <utility>

namespace ariel{
    OldNinja::OldNinja(std::string name, ariel::Point location): Ninja(std::move(name),location,O_NINJA_SPEED,O_NINJA_HIT_POINTS) {}
}