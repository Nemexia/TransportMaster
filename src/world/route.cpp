#include "route.hpp"

#include <cassert>
namespace game {
Route::Route(RouteId id) : id_(id) {}

RouteId Route::id() const {
    return id_;
}

void Route::add_station(StationId station) {
    stations_.push_back(station);
}

const std::vector<StationId>& Route::stations() const {
    return stations_;
}

RouteStopIndex Route::next_station(RouteStopIndex index) const {
    assert(!stations_.empty());
    assert(index.value < stations_.size());
    return RouteStopIndex{(index.value + 1) % stations_.size()};
}

StationId Route::station_at(RouteStopIndex index) const {
    assert(index.value < stations_.size());
    return stations_[index.value];
}
}  // namespace game