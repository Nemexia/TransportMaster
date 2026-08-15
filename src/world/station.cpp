#include "station.hpp"

namespace game {
Station::Station(StationId id, Position position) : id_(id), position_(position) {}

StationId Station::id() const {
    return id_;
}

Position Station::position() const {
    return position_;
}

void Station::add_route(RouteId route) {
    route_.push_back(route);
}

const std::vector<RouteId>& Station::routes() const {
    return route_;
}
}  // namespace game