#pragma once
#include "../game/game.h"

namespace game {
class Application {
public:
    Application();
    void run();

private:
    void update();
    void render();
    Game game_;
};
} // namespace game