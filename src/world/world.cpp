#include "world.hpp"

void game::World::update() {}

game::StationId game::World::create_station(game::Position position) {
    StationId id{next_station_id_++};
    station_.emplace_back(id, position);
    return id;
}

game::RouteId game::World::create_route() {
    RouteId id{next_route_id_++};
    route_.emplace_back(id);
    return id;
}

game::Station& game::World::station(game::StationId id) {
    return station_.at(id.value);
}
const game::Station& game::World::station(game::StationId id) const {
    return station_.at(id.value);
}

game::Route& game::World::route(RouteId id) {
    return route_.at(id.value);
}

const game::Route& game::World::route(RouteId id) const {
    return route_.at(id.value);
}

const std::vector<game::Station>& game::World::stations() const {
    return station_;
}

const std::vector<game::Route>& game::World::routes() const {
    return route_;
}
