#include "raylib.h"
#include "camera.h"
#include "settings.h"
#include "renderer/chunk.h"
#include "renderer/textures.h"
#include "worldgen/world.h"
#include "stats-windows/stats.h"

void start() {
    // render
    load_texture();
    load_defaults();
    generate_world();

    // camera
    setup_camera();

    // QOL
    DisableCursor();
}

void update_2D() {
    DrawText("F10 for cursor, F11 for fullscreen", 10, 30, 20, BLACK);
    // stats
    DrawText(TextFormat("FPS: %d\nMemory:\n%d KB\n%d MB",
        GetFPS(),
        getMemoryKB(),
        getMemoryKB()/1024
        ), 10, 60, 20, BLACK);
}

void update_3D() {
    settings_update();
    update_camera();
    render_world();
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Raycppcraft");
    start();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        update_3D();
        EndMode3D();
        update_2D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}