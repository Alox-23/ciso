#include "../include/chunk.h"

Chunk* chunk_create_chunk(){
  Chunk* chunk = malloc(sizeof(Chunk));
  if (!chunk) printf("Failed to Create World\n"); return NULL;

  chunk->is_dirty = true;

  return chunk;
}

void chunk_destroy_chunk(Chunk* chunk){
  if (!chunk) return;
  SDL_DestroyTexture(chunk->cached_texture);
  free(chunk);
  chunk = NULL;
}

World* chunk_create_world(size_t chunk_x, size_t chunk_y, size_t chunk_z){
  World* world = malloc(sizeof(World));
  if (!world) printf("Failed to Create World\n"); return NULL;
  
  world->chunk_x = chunk_x;
  world->chunk_y = chunk_y;
  world->chunk_z = chunk_z;

  size_t totalsize = chunk_x * chunk_y * chunk_z;
  world->chunks = (Chunk*)calloc(totalsize, sizeof(Chunk));

  if (!world->chunks){
    printf("Failed to initialize world->chunks array");
    return NULL;
  }

  for (size_t i = 0, i < totalsize; i++){
    world->chunks[i] = chunk_create_chunk();
  }
  
  return world;
}

void chunk_destroy_world(World* world){
  return;
}
