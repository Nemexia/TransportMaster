#pragma once
#include "types.h"

#include <vector>

namespace game {
struct Bus {
    BusId id;
    std::vector<PassengerId> passengers;
    RouteId route;
    StopIndex current_stop;
    double progression;
    double speed;
};
} // namespace game
