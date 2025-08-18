#include "../include/chunk.h"

Chunk* chunk_create_chunk(){
  Chunk* chunk = malloc(sizeof(Chunk));
  if (!chunk) return NULL;

  chunk->is_dirty = true;

  return chunk;
}

void chunk_destroy_chunk(Chunk* chunk){
  if (!chunk) return;
  free(chunk);
  chunk = NULL;
}
