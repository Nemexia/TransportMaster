#pragma once
#include "ids.hpp"
#include "position.hpp"
namespace game {
class Station {
  public:
    Station(StationId id, Position position);

    StationId id() const;
    Position position() const;

  private:
    StationId id_;
    Position position_;
};
}  // namespace game
