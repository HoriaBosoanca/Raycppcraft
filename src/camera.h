#pragma once

#include <iostream>
#include <bits/ostream.tcc>

#include "raylib.h"
#include "raymath.h"
#include "physics/physics.h"

inline Camera camera;

inline void setup_camera() {
    btVector3 pos = Physics::get_player_pos();
    camera.position = {pos.x(), pos.y(), pos.z()};
    camera.target = {1.0f, 0.0f, 1.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

constexpr float SPEED = 1000000.0f;
inline void wasd() {
    btVector3 pos = Physics::get_player_pos();
    Vector3 diff = Vector3Subtract(camera.target, camera.position);
    camera.position = Vector3(pos.x(), pos.y()+0.5f, pos.z());
    camera.target = Vector3(pos.x()+diff.x, pos.y()+diff.y+0.5f, pos.z()+diff.z);
    Vector3 raw_direction = Vector3Normalize(diff);
    Vector2 direction(raw_direction.x*SPEED*GetFrameTime(), raw_direction.z*SPEED*GetFrameTime());
    if (IsKeyDown(KEY_W)) {
        Physics::add_force_player(direction.x, 0.0f, direction.y);
    }
    if (IsKeyDown(KEY_A)) {
        Physics::add_force_player(direction.y, 0.0f, -direction.x);
    }
    if (IsKeyDown(KEY_S)) {
        Physics::add_force_player(-direction.x, 0.0f, -direction.y);
    }
    if (IsKeyDown(KEY_D)) {
        Physics::add_force_player(-direction.y, 0.0f, direction.x);
    }
}

constexpr float JUMP_FORCE = 10000000.0f;
inline bool is_jumping = false;
inline void jump() {
    std::cout << "tick\n";
    if (is_jumping && Physics::did_player_collide_any()) {
        is_jumping = false;
    }
    if (IsKeyDown(KEY_SPACE) && !is_jumping) {
        std::cout << "jump\n";
        is_jumping = true;
        Physics::add_force_player(0.0f, JUMP_FORCE*GetFrameTime(), 0.0f);
    }
}

const btVector3 MAX_VELOCITY = btVector3(100000.0f, 100000.0f, 100000.0f);
inline void clamp_velocity() {
    btVector3 vel = Physics::playerRb->getLinearVelocity();
    if (vel.x() > MAX_VELOCITY.x()) {
        vel.setX(MAX_VELOCITY.x());
    }
    if (vel.y() > MAX_VELOCITY.y()) {
        vel.setY(MAX_VELOCITY.y());
    }
    if (vel.z() > MAX_VELOCITY.z()) {
        vel.setZ(MAX_VELOCITY.z());
    }
    Physics::playerRb->setAngularVelocity(MAX_VELOCITY);
}

inline void update_camera() {
    wasd();
    jump();
    // clamp_velocity();
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
}