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
    RouteStopIndex next_station(RouteStopIndex index) const;
    StationId station_at(RouteStopIndex index) const;

  private:
    RouteId id_;
    std::vector<StationId> stations_;
};
}  // namespace game