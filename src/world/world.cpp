#include "world.hpp"
namespace game {
void World::update() {}

StationId World::add_station(Position position) {
    StationId id{next_station_id_++};
    stations_.emplace_back(id, position);
    return id;
}

RouteId World::add_route() {
    RouteId id{next_route_id_++};
    routes_.emplace_back(id);
    return id;
}

BusId World::add_bus(RouteId route_id) {
    route(route_id);
    BusId id{next_bus_id_++};
    buses_.emplace_back(id, route_id);
    return id;
}

Station& World::station(StationId id) {
    return stations_.at(id.value);
}
const Station& World::station(StationId id) const {
    return stations_.at(id.value);
}

Route& World::route(RouteId id) {
    return routes_.at(id.value);
}

const Route& World::route(RouteId id) const {
    return routes_.at(id.value);
}

Bus& World::bus(BusId id) {
    return buses_.at(id.value);
}

const Bus& World::bus(BusId id) const {
    return buses_.at(id.value);
}

const std::vector<Station>& World::stations() const {
    return stations_;
}

const std::vector<Route>& World::routes() const {
    return routes_;
}

const std::vector<Bus>& World::buses() const {
    return buses_;
}

void World::add_station_to_route(RouteId route_id, StationId station_id) {
    Route& r = route(route_id);
    Station& s = station(station_id);
    if (!r.stations().empty()) {
        if (r.stations().back().value == station_id.value) {
            return;
        }
    }
    r.add_station(station_id);
    s.add_route(route_id);
}
}  // namespace game