#pragma once

#include "raylib.h"

inline Camera camera;

inline float SPEED_Y;

inline void setup_camera() {
    camera.position = {1.0f, 32.0f, 1.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

inline void update_camera() {
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    SPEED_Y = IsKeyDown(KEY_LEFT_CONTROL) ? 100.0f : 10.0f;
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        camera.position.y -= SPEED_Y * GetFrameTime();
        camera.target.y -= SPEED_Y * GetFrameTime();
    }
    if (IsKeyDown(KEY_SPACE)) {
        camera.position.y += SPEED_Y * GetFrameTime();
        camera.target.y += SPEED_Y * GetFrameTime();
    }
}