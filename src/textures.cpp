#include "raylib.h"

Texture2D T_ATLAS;

void load_textures() {
    T_ATLAS = LoadTexture("assets/atlas.png");
}