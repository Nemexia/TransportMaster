#include "route.hpp"

#include <cassert>

game::Route::Route(RouteId id) : id_(id) {}

game::RouteId game::Route::id() const {
    return id_;
}

void game::Route::add_station(StationId station) {
    stations_.push_back(station);
}

const std::vector<game::StationId>& game::Route::stations() const {
    return stations_;
}

std::size_t game::Route::next_station(std::size_t index) const {
    assert(!stations_.empty());
    assert(index < stations_.size());
    return (index + 1) % stations_.size();
}
