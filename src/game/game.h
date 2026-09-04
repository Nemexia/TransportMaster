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

struct Route {
    std::vector<StationId> stops;
};

struct Station {
    StationId id;
    Position position;
    std::string name;
};

struct Game {};
} // namespace game