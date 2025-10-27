#include "raylib.h"
#include "camera.h"
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
    // ToggleFullscreen();
}

void update_2D() {
    // stats
    DrawText(TextFormat("FPS: %d\nMemory:\n%d KB\n%d MB",
        GetFPS(),
        getMemoryKB(),
        getMemoryKB()/1024
        ), 10, 10, 20, BLACK);
}

void update_3D() {
    update_camera();
    render_world();
}

int main() {
    InitWindow(3440, 1300, "Raycppcraft");
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