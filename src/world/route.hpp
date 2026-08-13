#pragma once
#include <vector>

#include "ids.hpp"
namespace game {
class Route {
  public:
    Route(RouteId id);
    RouteId id() const;
    void add_station(StationId station);
    const std::vector<StationId>& stations() const;
    std::size_t next_station(std::size_t index) const;

  private:
    RouteId id_;
    std::vector<StationId> stations_;
};
}  // namespace game