#pragma once
#include "bus.h"
#include "passenger.h"
#include "route.h"
#include "station.h"

#include <vector>

namespace game {
struct State {
    std::vector<Bus> buses;
    std::vector<Passenger> passengers;
    std::vector<Route> routes;
    std::vector<Station> stations;
};
} // namespace game
