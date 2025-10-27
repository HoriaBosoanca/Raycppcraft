#include "world.h"
#include "../renderer/chunk.h"

Chunk chunk;

void generate_world() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                chunk.add_block({(float) i, (float) k, (float) j}, BLOCK::GRASS);
            }
        }
    }
    chunk.build_model();
}

void render_world() {
    chunk.draw_model({0, 0, 0});
}
