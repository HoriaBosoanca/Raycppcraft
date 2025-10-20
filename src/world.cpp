#include "world.h"
#include "chunk.h"

Chunk chunk;

void load_chunks() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                chunk.add_block({i, k, j}, BLOCK::GRASS);
            }
        }
    }
    chunk.build_model();
}