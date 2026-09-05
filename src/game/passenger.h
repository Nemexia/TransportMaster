#pragma once
#include "types.h"

namespace game {
struct Passenger {
    PassengerId id;
    StationId origin;
    StationId destination;
};
} // namespace game
