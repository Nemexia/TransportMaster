#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace game {
struct Position {
    double x;
    double y;
};

using StationId = std::uint32_t;
using RouteId = std::uint32_t;
using PassengerId = std::uint32_t;
using BusId = std::uint32_t;

struct Passenger {
    StationId origin;
    StationId destination;
};

struct Route {
    RouteId id;
    std::vector<StationId> stops;
    std::vector<BusId> buses;
};

struct Station {
    StationId id;
    Position position;
    std::string name;
    std::vector<PassengerId> passengers;
    std::vector<RouteId> routes;
};

struct Bus {
    BusId id;
    RouteId route;
    std::vector<PassengerId> passengers;
    double speed;
};

struct Game {
    Game();
    std::vector<Station> stations;
    std::vector<Route> routes;
    std::vector<Bus> buses;
    std::vector<Passenger> passengers;
};
} // namespace game