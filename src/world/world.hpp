#pragma once
#include <cstdint>
#include <vector>

#include "station.hpp"

namespace game {
class World {
  public:
    void update();
    StationId create_station(Position position);
    Station& station(StationId id);
    const Station& station(StationId id) const;

  private:
    std::vector<Station> station_;
    std::uint32_t next_station_id_;
};
}  // namespace game
