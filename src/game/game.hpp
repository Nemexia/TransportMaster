#pragma once
#include "../graphics/renderer.hpp"
#include "../world/world.hpp"
namespace game {
class Game {
  public:
    Game();
    void update();
    void draw();

  private:
    World world_;
    Renderer renderer_;
};
}  // namespace game