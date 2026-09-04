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

void Application::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Hello, TransportMaster!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}
} // namespace game
