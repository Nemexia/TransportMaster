#pragma once
#include "../game/game.hpp"
namespace game {
class Application {
  public:
    int run();

  private:
    void initialize();
    void shutdown();

    Game game_;
};
}  // namespace game