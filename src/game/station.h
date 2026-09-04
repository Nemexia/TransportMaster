#pragma once
#include "position.h"
#include "types.h"

#include <string>
#include <vector>

namespace game {
struct Station {
    StationId id;
    Position position;
    std::string name;
    std::vector<PassengerId> passengers;
    double spawn_chance;
};
} // namespace game
