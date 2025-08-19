#include "../include/chunk.h"

void chunk_create_chunk(Chunk *chunk){
  if (!chunk){
    printf("Invalid chunk pointer\n");
    return;
  }

  chunk->is_dirty = true;
}

void chunk_destroy_chunk(Chunk* chunk){
  if (!chunk) return;
  SDL_DestroyTexture(chunk->cached_texture);
  free(chunk);
  chunk = NULL;
}
