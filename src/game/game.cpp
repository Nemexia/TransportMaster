#include "game.hpp"

#include <raylib.h>

void game::Game::update() {
    world_.update();
}

void game::Game::draw() {
    ClearBackground(RAYWHITE);
}
