#pragma once
#include <cstdint>
namespace game {
struct StationId {
    std::uint32_t value;
};

struct RouteId {
    std::uint32_t value;
};

struct BusId {
    std::uint32_t value;
};

struct PassengerId {
    std::uint32_t value;
};
}  // namespace game