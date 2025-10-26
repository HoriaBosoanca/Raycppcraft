#include "raylib.h"
#include "chunk.h"
#include "camera.h"
#include "stats.h"
#include "textures.h"
#include "world.h"

void start() {
    load_texture();

    setup_camera();
    DisableCursor();
    // ToggleFullscreen();

    load_defaults();
    load_chunks();
}

void update_2D() {
    DrawText(TextFormat("FPS: %d\nMemory: %d KB",
        GetFPS(),
        getMemoryKB()
        ), 10, 10, 20, BLACK);
}

void update_3D() {
    update_camera();
    chunk.draw_model({0, 0, 0});
}

int main() {
    InitWindow(1920, 900, "Raycppcraft");
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