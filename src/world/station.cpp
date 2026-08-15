#include "station.hpp"

#include <algorithm>

#include "ids.hpp"

namespace game {
Station::Station(StationId id, Position position) : id_(id), position_(position) {}

StationId Station::id() const {
    return id_;
}

Position Station::position() const {
    return position_;
}

void Station::add_route(RouteId route) {
    if (std::find_if(routes_.begin(), routes_.end(), [&route](const RouteId& id) {
            return id.value == route.value;
        }) == routes_.end()) {
        routes_.push_back(route);
    }
}

const std::vector<RouteId>& Station::routes() const {
    return routes_;
}
}  // namespace game