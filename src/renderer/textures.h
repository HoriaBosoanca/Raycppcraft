#pragma once

#include <map>
#include <array>

const float ATLAS_UNIT = 1.0f/8.0f;
inline Texture2D ATLAS;
inline void load_texture() {
    ATLAS = LoadTexture("assets/atlas.png");
}

inline Vector2 AIR = Vector2{2.0f, 6.0f};
inline Vector2 GRASS_TOP = Vector2{0.0f, 7.0f};
inline Vector2 GRASS_SIDE = Vector2{0.0f, 6.0f};
inline Vector2 DIRT = Vector2{1.0f, 7.0f};
inline Vector2 STONE = Vector2{4.0f, 6.0f};

enum BLOCK {
    B_AIR,
    B_GRASS,
    B_DIRT,
    B_STONE
};

inline std::map<BLOCK, std::array<Vector2, 6>> t_map = {
    {B_AIR,   {AIR, AIR, AIR, AIR, AIR, AIR}},
    {B_GRASS, {GRASS_SIDE, GRASS_SIDE, GRASS_TOP, DIRT, GRASS_SIDE, GRASS_SIDE}},
    {B_DIRT,  {DIRT, DIRT, DIRT, DIRT, DIRT, DIRT}},
    {B_STONE, {STONE, STONE, STONE, STONE, STONE, STONE}}
};