#pragma once
#include "color.h"
#include "types.h"

#include <vector>

namespace game {
class Route {
public:
    StopIndex next_stop(StopIndex current_stop) const;

private:
    RouteId id;
    std::vector<StationId> stops;
    Color color;
};
} // namespace game
