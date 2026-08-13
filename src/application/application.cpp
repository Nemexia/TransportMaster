#include "application.hpp"

#include <raylib.h>

int game::Application::run() {
    initialize();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    shutdown();
    return 0;
}

void game::Application::initialize() {
    InitWindow(800, 600, "TransportMaster");
    SetTargetFPS(60);
}

void game::Application::shutdown() {
    CloseWindow();
}
