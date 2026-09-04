#pragma once
#include "color.h"
#include "types.h"

#include <vector>

namespace game {
struct Route {
    RouteId id;
    std::vector<StationId> stops;
    Color color;
};
} // namespace game
