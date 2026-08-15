#pragma once
#include <vector>

#include "ids.hpp"
#include "position.hpp"
namespace game {
class Station {
  public:
    Station(StationId id, Position position);

    StationId id() const;
    Position position() const;

    void add_route(RouteId route);
    const std::vector<RouteId>& routes() const;

  private:
    StationId id_;
    Position position_;

    std::vector<RouteId> routes_;
};
}  // namespace game
