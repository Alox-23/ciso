#ifndef CHUNK_H
#define CHUNK_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define CHUNK_SIZE 16

typedef struct{
  uint8_t tiles[CHUNK_SIZE][CHUNK_SIZE];
  SDL_Texture* cached_texture;
  bool is_dirty;
}Chunk;

typedef struct{
  Chunk* chunks;
  size_t chunk_x, chunk_y, chunk_z;
}World;

#endif
