#pragma once
#include "color.h"
#include "position.h"
#include "state.h"
#include "types.h"

#include <span>
#include <string_view>

namespace game {
class Game {
public:
    StationId add_station(const Position& position, std::string_view name, double spawn_chance);
    RouteId add_route(std::span<const StationId> stops, const Color& color);
    BusId add_bus(RouteId route, double speed);
    PassengerId add_passenger(StationId origin, StationId destination);

    State& state();

private:
    State state_;
};
} // namespace game
