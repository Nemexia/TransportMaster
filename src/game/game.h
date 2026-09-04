#pragma once
#include "state.h"

namespace game {
class Game {
public:
    Game();
    StationId add_station(const Position& position, const std::string& name);
    RouteId add_route(const std::vector<StationId>& stops, const Color& color);
    BusId add_bus(RouteId route, double speed);
    PassengerId add_passenger(StationId origin, StationId destination);

private:
    State state_;
};
} // namespace game