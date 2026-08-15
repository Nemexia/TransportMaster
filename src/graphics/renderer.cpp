#include "renderer.hpp"

#include <raylib.h>

#include "../world/world.hpp"
namespace game {
void Renderer::draw(const World& world) {
    ClearBackground(RAYWHITE);

    for (const Route& route : world.routes()) {
        const auto& stations = route.stations();

        if (stations.size() < 2) {
            continue;
        }

        for (std::size_t i = 0; i < stations.size(); ++i) {
            const std::size_t next = route.next_station(i);
            const auto a = world.station(stations[i]).position();
            const auto b = world.station(stations[next]).position();
            DrawLine(a.x, a.y, b.x, b.y, GREEN);
        }
    }

    for (const Station& station : world.stations()) {
        constexpr int size = 10;
        constexpr int offset = size / 2;
        const Position position = station.position();
        DrawRectangle(position.x - offset, position.y - offset, size, size, BLACK);
    }
}
}  // namespace game