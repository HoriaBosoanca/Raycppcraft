#include "globals.h"
#include "cube.h"
#include "raylib.h"
#include "textures.h"

Model cube;

void start() {
    load_textures();
    camera.position = {4.0f, 4.0f, 4.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Mesh cube_mesh = GenMeshCube(1.0f, 1.0f, 1.0f);
    cube = LoadModelFromMesh(cube_mesh);
    cube.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = T_ATLAS;
}

void update_2D() {
    // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}

void update_3D() {
    draw_cube(cube, {0.0f, 0.0f, 0.0f}, WHITE);
}

int main() {
    InitWindow(800, 450, "Raycppcraft");
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