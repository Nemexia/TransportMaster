#pragma once
#include <cstdint>
#include <vector>

#include "route.hpp"
#include "station.hpp"

namespace game {
class World {
  public:
    void update();

    StationId create_station(Position position);
    RouteId create_route();

    Station& station(StationId id);
    const Station& station(StationId id) const;

    Route& route(RouteId id);
    const Route& route(RouteId id) const;

    const std::vector<Station>& stations() const;
    const std::vector<Route>& routes() const;

  private:
    std::vector<Station> station_;
    std::vector<Route> route_;

    std::uint32_t next_station_id_{};
    std::uint32_t next_route_id_{};
};
}  // namespace game
