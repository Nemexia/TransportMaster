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

std::size_t Route::next_station(std::size_t index) const {
    assert(!stations_.empty());
    assert(index < stations_.size());
    return (index + 1) % stations_.size();
}
}  // namespace game