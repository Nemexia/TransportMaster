#include "game.hpp"

void game::Game::update() {
    world_.update();
}

void game::Game::draw() {
    renderer_.draw(world_);
}
