#include "station.hpp"

game::Station::Station(game::StationId id, game::Position position)
    : id_(id), position_(position) {}

game::StationId game::Station::id() const {
    return id_;
}

game::Position game::Station::position() const {
    return position_;
}
