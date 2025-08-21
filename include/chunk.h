#ifndef CHUNK_H
#define CHUNK_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/texturemanager.h"

#define CHUNK_SIZE 32

typedef struct{
  uint8_t tiles[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
  SDL_Texture* cached_texture;
  bool is_dirty;
}Chunk;

void chunk_create(Chunk* chunk);
void chunk_destroy(Chunk* chunk);
void chunk_update_cache();

#endif
