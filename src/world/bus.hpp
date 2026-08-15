#pragma once
#include "ids.hpp"
namespace game {
class Bus {
  public:
    Bus(BusId id, RouteId route_id);

    BusId id() const;
    RouteId route_id() const;

    RouteStopIndex current_stop() const;
    double progress() const;

  private:
    BusId id_;
    RouteId route_id_;

    RouteStopIndex current_stop_{};
    double progress_{};
};
}  // namespace game