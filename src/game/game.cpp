#include "game.h"

#include "color.h"
#include "position.h"
#include "types.h"

#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace game {
StationId Game::add_station(const Position& position, std::string_view name, double spawn_chance) {
    StationId id = static_cast<StationId>(state_.stations.size());
    state_.stations.emplace_back(id, position, std::string(name), std::vector<PassengerId>(), spawn_chance);
    return id;
}

RouteId Game::add_route(std::span<const StationId> stops, const Color& color) {
    RouteId id = static_cast<RouteId>(state_.routes.size());
    state_.routes.emplace_back(id, std::vector<StationId>(stops.begin(), stops.end()), color);
    return id;
}

BusId Game::add_bus(RouteId route, double speed) {
    BusId id = static_cast<BusId>(state_.buses.size());
    state_.buses.emplace_back(id, std::vector<PassengerId>{}, route, 0, 0.0, speed);
    return id;
}

PassengerId Game::add_passenger(StationId origin, StationId destination) {
    PassengerId id = static_cast<PassengerId>(state_.passengers.size());
    state_.passengers.emplace_back(id, origin, destination);
    return id;
}
} // namespace game
