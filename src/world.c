#include "../include/world.h"

World* world_create(size_t chunk_x, size_t chunk_y, size_t chunk_z){
  World* world = malloc(sizeof(World));
  if (!world){
    printf("Failed to Create World\n");
    return NULL;
  }

  world->chunk_x = chunk_x;
  world->chunk_y = chunk_y;
  world->chunk_z = chunk_z;

  size_t totalsize = chunk_x * chunk_y * chunk_z;
  world->chunks = malloc(totalsize * sizeof(Chunk));
  if (!world->chunks){
    printf("Failed to initialize world->chunks array");
    return NULL;
  }

  for (size_t i = 0; i < totalsize; i++){
    chunk_create(&world->chunks[i]);
  }
  
  return world;
}

Chunk* world_get_chunk(World* world, size_t chunk_x, size_t chunk_y, size_t chunk_z){
  if (!world){
    printf("Invalid world pointer passed to world_get_chunk()\n");
    return NULL;
  }

  if (chunk_x >= world->chunk_x || chunk_y >= world->chunk_y || chunk_z >= world->chunk_z){
    printf("Index out of bounds in world_get_chunk\n");
    return NULL;
  }

  size_t index = chunk_x * world->chunk_y * world->chunk_z + chunk_y * world->chunk_z + chunk_z;
  return &world->chunks[index];
}

void world_destroy(World* world){
  if (!world){
    printf("Invalid world pointer passed to chunk_destroy_world\n");
    return;
  }
  for (size_t i = 0; i < world->chunk_x * world->chunk_y * world->chunk_z; i++){
    chunk_destroy(&world->chunks[i]);
  }

  free(world->chunks);
  free(world);
}
