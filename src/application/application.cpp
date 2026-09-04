#include "application.h"

#include <raylib.h>

namespace game {
Application::Application() {
    InitWindow(800, 600, "TransportMaster");
    SetTargetFPS(60);
}

void Application::run() {
    while (!WindowShouldClose()) {
        update();
        render();
    }
    CloseWindow();
}

void Application::update() {}

static void draw(const Game& game) {
    for (const auto& route : game.routes) {
        for (size_t i = 0; i < route.stops.size() - 1; ++i) {
            const auto& startStation = game.stations[route.stops[i]];
            const auto& endStation = game.stations[route.stops[i + 1]];
            DrawLine(static_cast<int>(startStation.position.x + 10), static_cast<int>(startStation.position.y + 10),
                     static_cast<int>(endStation.position.x + 10), static_cast<int>(endStation.position.y + 10), GRAY);
        }
    }

    for (const auto& station : game.stations) {
        DrawRectangle(static_cast<int>(station.position.x), static_cast<int>(station.position.y), 20, 20, BLACK);
        DrawText(station.name.c_str(), static_cast<int>(station.position.x), static_cast<int>(station.position.y) - 20,
                 10, BLACK);
        DrawText(std::to_string(station.passengers.size()).c_str(), static_cast<int>(station.position.x) + 5,
                 static_cast<int>(station.position.y) + 5, 10, WHITE);
    };
}

void Application::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    draw(game_);
    EndDrawing();
}
} // namespace game
