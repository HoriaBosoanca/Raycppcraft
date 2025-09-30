#include "raylib.h"
#include <stdio.h>
#include <iostream>

int main() {
    printf("HI\n");
    std::cout << "HI\n";
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Basic raylib example");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update (put your logic here)

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, raylib!", 350, 200, 20, DARKGRAY);
        DrawCircle(screenWidth/2, screenHeight/2, 50, RED);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
