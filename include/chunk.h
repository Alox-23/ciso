#ifndef CHUNK_H
#define CHUNK_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/texturemanager.h"

#define CHUNK_SIZE 16

typedef struct{
  uint8_t tiles[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
  SDL_Texture* cached_texture;
  bool is_dirty;
}Chunk;

Chunk chunk_create_chunk();
void chunk_destroy_chunk(Chunk* chunk);
void chunk_update_cache();

#endif
