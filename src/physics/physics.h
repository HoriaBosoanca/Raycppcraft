#pragma once

#include "btBulletDynamicsCommon.h"

namespace Physics
{
    extern btRigidBody* playerRb;
    void init();
    void update();
    void add_static_cube(float x, float y, float z);
    void init_player();
    void add_force_player(float x, float y, float z);
    btVector3 get_player_pos();
    bool did_player_collide_any();
}
