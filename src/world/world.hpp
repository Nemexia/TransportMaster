#pragma once
#include <cstdint>
#include <vector>

#include "bus.hpp"
#include "route.hpp"
#include "station.hpp"

namespace game {
class World {
  public:
    void update();

    StationId add_station(Position position);
    void add_station_to_route(RouteId route_id, StationId station_id);
    RouteId add_route();
    BusId add_bus(RouteId route_id);

    Station& station(StationId id);
    const Station& station(StationId id) const;

    Route& route(RouteId id);
    const Route& route(RouteId id) const;

    Bus& bus(BusId id);
    const Bus& bus(BusId id) const;

    const std::vector<Station>& stations() const;
    const std::vector<Route>& routes() const;
    const std::vector<Bus>& buses() const;

  private:
    std::vector<Station> stations_;
    std::vector<Route> routes_;
    std::vector<Bus> buses_;

    std::uint32_t next_station_id_{};
    std::uint32_t next_route_id_{};
    std::uint32_t next_bus_id_{};
};
}  // namespace game
