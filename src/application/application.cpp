#include "application.hpp"

#include <raylib.h>
namespace game {
int Application::run() {
    initialize();
    while (!WindowShouldClose()) {
        game_.update();
        BeginDrawing();
        game_.draw();
        EndDrawing();
    }
    shutdown();
    return 0;
}

void Application::initialize() {
    InitWindow(800, 600, "TransportMaster");
    SetTargetFPS(60);
}

void Application::shutdown() {
    CloseWindow();
}
}  // namespace game