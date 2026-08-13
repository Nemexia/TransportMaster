#pragma once
#include "../world/world.hpp"
namespace game {
class Game {
  public:
    void update();
    void draw();

  private:
    World world_;
};
}  // namespace game