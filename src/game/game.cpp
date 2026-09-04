#include "game.h"

namespace game {
Game::Game() {
    stations = {
        {0, {100, 100}, "Station A", {}, {0}},
        {1, {300, 100}, "Station B", {}, {0}},
        {2, {500, 100}, "Station C", {}, {0}},
    };

    routes = {
        {0, {0, 1, 2}, {}},
    };
}
} // namespace game
