#include "application.h"

#include <array>
#include <raylib.h>

namespace game {
Application::Application() {
    InitWindow(800, 600, "TransportMaster");
    SetTargetFPS(60);

    const auto station_1 = game_.add_station({100, 100}, "Station A", 0.1);
    const auto station_2 = game_.add_station({300, 100}, "Station B", 0.1);
    const auto station_3 = game_.add_station({300, 300}, "Station C", 0.1);

    const auto route_1 = game_.add_route(std::array{station_1, station_2, station_3}, {255, 0, 0});

    const auto bus_1 = game_.add_bus(route_1, 0.5);
    // TODOES:  need to add bus to route too
    const auto passenger_1 = game_.add_passenger(station_1, station_3);
}

void Application::run() {
    while (!WindowShouldClose()) {
        update();
        render();
    }
    CloseWindow();
}

void Application::update() {}

static void draw(const game::State& state) {
    for (const auto& route : state.routes) {
        for (size_t i = 0; i < route.stops.size() - 1; ++i) {
            const auto& startStation = state.stations[route.stops[i]];
            const auto& endStation = state.stations[route.stops[i + 1]];
            DrawLine(static_cast<int>(startStation.position.x + 10), static_cast<int>(startStation.position.y + 10),
                     static_cast<int>(endStation.position.x + 10), static_cast<int>(endStation.position.y + 10),
                     {route.color.r, route.color.g, route.color.b, 255});
        }
    }

    for (const auto& station : state.stations) {
        DrawRectangle(static_cast<int>(station.position.x), static_cast<int>(station.position.y), 20, 20, ::BLACK);
        DrawText(station.name.c_str(), static_cast<int>(station.position.x), static_cast<int>(station.position.y) - 20,
                 10, ::BLACK);
        DrawText(std::to_string(station.passengers.size()).c_str(), static_cast<int>(station.position.x) + 5,
                 static_cast<int>(station.position.y) + 5, 10, ::WHITE);
    };

    for (const auto& bus : state.buses) {
        const auto& route = state.routes[bus.route];
        const auto& startStation = state.stations[route.stops[bus.current_stop]];
        const auto& endStation = state.stations[route.stops[bus.current_stop + 1]];
        const double x = startStation.position.x + (endStation.position.x - startStation.position.x) * bus.progression;
        const double y = startStation.position.y + (endStation.position.y - startStation.position.y) * bus.progression;
        DrawRectangle(static_cast<int>(x), static_cast<int>(y), 20, 20,
                      {route.color.r, route.color.g, route.color.b, 255});
        DrawText(std::to_string(bus.passengers.size()).c_str(), static_cast<int>(x) + 5, static_cast<int>(y) + 5, 10,
                 ::WHITE);
    }
}

void Application::render() {
    BeginDrawing();
    ClearBackground(::RAYWHITE);
    draw(game_.state_);
    EndDrawing();
}
} // namespace game
