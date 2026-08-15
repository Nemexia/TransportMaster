#include "station.hpp"

namespace game {
Station::Station(StationId id, Position position) : id_(id), position_(position) {}

StationId Station::id() const {
    return id_;
}

Position Station::position() const {
    return position_;
}

}  // namespace game