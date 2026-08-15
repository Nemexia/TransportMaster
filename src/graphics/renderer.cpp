#include "renderer.hpp"

#include <raylib.h>

#include "../world/world.hpp"
namespace game {
void Renderer::draw(const World& world) {
    ClearBackground(RAYWHITE);

    for (const Route& route : world.routes()) {
        const auto& station_ids = route.stations();

        if (station_ids.size() < 2) {
            continue;
        }

        for (std::size_t i = 0; i < route.stop_count(); ++i) {
            const RouteStopIndex current{i};
            const RouteStopIndex next = route.next_station(current);
            const Position a = world.station(route.station_at(current)).position();
            const Position b = world.station(route.station_at(next)).position();
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