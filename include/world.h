#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include "../include/chunk.h"

typedef struct{
  Chunk* chunks;
  size_t chunk_x, chunk_y, chunk_z;
}World;

World* world_create_world(size_t chunk_x, size_t chunk_y, size_t chunk_z);
void world_destroy_world(World* world);

#endif
