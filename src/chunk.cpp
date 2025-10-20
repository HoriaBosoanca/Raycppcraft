#include "chunk.h"
#include <cstdlib>
#include "textures.h"

Mesh cube;
void load_example_cube() {
    cube = GenMeshCube(1.0f, 1.0f, 1.0f);
}

void Chunk::add_block(Vector3 local_pos, BLOCK block) {
    for (int i = 0; i < cube.vertexCount * 3; i += 3) {
        vertices.push_back(cube.vertices[i + 0] + local_pos.x);
        vertices.push_back(cube.vertices[i + 1] + local_pos.y);
        vertices.push_back(cube.vertices[i + 2] + local_pos.z);
    }
    normals.insert(normals.end(), cube.normals, cube.normals + cube.vertexCount * 3);
    for (int i = 0; i < 48; i++) { // cube.vertexCount = 48
        if (i%2 == 0) { // even = U
            // using "1.0f-" to flip the texture
            texcoords.push_back((1.0f-cube.texcoords[i] + t_map[block][i/8].x) * ATLAS_UNIT);
        } else { // odd = V
            texcoords.push_back((1.0f-cube.texcoords[i] + t_map[block][i/8].y) * ATLAS_UNIT);
        }
    }
    for (int i = 0; i < cube.triangleCount * 3; i++) {
        indices.push_back(cube.indices[i] + vertexCount);
    }
    vertexCount += cube.vertexCount;
    triangleCount += cube.triangleCount;
}

void Chunk::build_model() {
    Mesh mesh = { 0 };

    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;
    mesh.vertices = new float[vertices.size()];
    std::copy(vertices.begin(), vertices.end(), mesh.vertices);
    mesh.normals = new float[normals.size()];
    std::copy(normals.begin(), normals.end(), mesh.normals);
    mesh.texcoords = new float[texcoords.size()];
    std::copy(texcoords.begin(), texcoords.end(), mesh.texcoords);
    mesh.indices = new unsigned short[indices.size()];
    std::copy(indices.begin(), indices.end(), mesh.indices);

    UploadMesh(&mesh, false);
    model = LoadModelFromMesh(mesh);
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = ATLAS;

    delete[] mesh.vertices;
    delete[] mesh.normals;
    delete[] mesh.texcoords;
    delete[] mesh.indices;
}

void Chunk::draw_model(Vector3 position) {
    DrawModel(model, position, 1.0, WHITE);
}