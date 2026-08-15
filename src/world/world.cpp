#include "world.hpp"
namespace game {
void World::update() {}

StationId World::add_station(Position position) {
    StationId id{next_station_id_++};
    station_.emplace_back(id, position);
    return id;
}

RouteId World::add_route() {
    RouteId id{next_route_id_++};
    route_.emplace_back(id);
    return id;
}

Station& World::station(StationId id) {
    return station_.at(id.value);
}
const Station& World::station(StationId id) const {
    return station_.at(id.value);
}

Route& World::route(RouteId id) {
    return route_.at(id.value);
}

const Route& World::route(RouteId id) const {
    return route_.at(id.value);
}

const std::vector<Station>& World::stations() const {
    return station_;
}

const std::vector<Route>& World::routes() const {
    return route_;
}

void World::add_station_to_route(RouteId route_id, StationId station_id) {
    Route& r = route(route_id);
    Station& s = station(station_id);
    r.add_station(station_id);
    s.add_route(route_id);
}
}  // namespace game