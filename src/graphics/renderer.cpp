#include "renderer.hpp"

#include <raylib.h>

#include "../world/world.hpp"

void game::Renderer::draw(const game::World& world) {
    ClearBackground(RAYWHITE);

    for (const Station& station : world.stations()) {
        constexpr int size = 10;
        constexpr int offset = size / 2;
        const Position position = station.position();
        DrawRectangle(position.x - offset, position.y - offset, size, size, BLACK);
    }
}