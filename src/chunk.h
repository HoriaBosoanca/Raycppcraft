#pragma once

#include <vector>
#include "raylib.h"
#include "textures.h"

void load_example_cube();

class Chunk {
    public:
    Model model = { 0 };
    int vertexCount = 0;
    int triangleCount = 0;
    std::vector<float> vertices;
    std::vector<unsigned short> indices;
    std::vector<float> normals;
    std::vector<float> texcoords;
    void build_model();
    void draw_model(Vector3 position);
    void add_block(Vector3 local_pos, BLOCK block);
};
