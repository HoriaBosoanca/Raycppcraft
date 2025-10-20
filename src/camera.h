#pragma once

#include "raylib.h"

inline Camera camera;

inline void setup_camera() {
    camera.position = {4.0f, 4.0f, 4.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

inline void update_camera() {
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        camera.position.y -= 0.01f;
        camera.target.y -= 0.01f;
    }
    if (IsKeyDown(KEY_SPACE)) {
        camera.position.y += 0.01f;
        camera.target.y += 0.01f;
    }
}