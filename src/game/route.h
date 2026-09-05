#pragma once
#include "color.h"
#include "types.h"

#include <vector>

namespace game {
class Route {
public:
    StopIndex next_stop(StopIndex current_stop) const;
    StationId stop_station(StopIndex stop_index) const;
    Color color() const;

private:
    RouteId id;
    std::vector<StationId> stops;
    std::vector<BusId> buses;
    Color color;
};
} // namespace game
