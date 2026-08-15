#include "bus.hpp"
namespace game {
Bus::Bus(BusId id, RouteId route_id) : id_(id), route_id_(route_id) {}

BusId Bus::id() const {
    return id_;
}

RouteId Bus::route_id() const {
    return route_id_;
}

RouteStopIndex Bus::current_stop() const {
    return current_stop_;
}

double Bus::progress() const {
    return progress_;
}
}  // namespace game