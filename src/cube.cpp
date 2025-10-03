#include "raylib.h"

void draw_cube(Model& cube, Vector3 position, Color color = RED) {
    DrawModel(cube, position, 1.0, color);
}