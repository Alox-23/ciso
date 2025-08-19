#include "../include/chunk.h"

Chunk chunk_create_chunk(){
  Chunk chunk; 
  chunk.is_dirty = true;
  memset(chunk.tiles, 1, sizeof(chunk.tiles));
  return chunk;
}

void chunk_update_cache(Chunk* chunk, SDL_Renderer* renderer, TextureManager* texture_manager){
  if (!chunk){
    printf("Invalid chunk pointer to update_cache\n");
    return;
  }

  if (!renderer){
    printf("invalid sdl renderer\n");
    return;
  }

  if (!texture_manager){
    printf("invalid texture manager\n");
    return;
  }

  if (!chunk->is_dirty) return; //no error but there is no need to run function
  
  if (chunk->cached_texture) {
    SDL_DestroyTexture(chunk->cached_texture);
  }

  chunk->cached_texture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    CHUNK_SIZE * texture_manager->texture_width,
    CHUNK_SIZE * texture_manager->texture_height
  );

  SDL_SetRenderTarget(renderer, chunk->cached_texture);
  SDL_RenderClear(renderer);

  Vector3 iv;
  Vector2 scale = {texture_manager->texture_width, texture_manager->texture_height};
  Vector2 sv;
  SDL_Rect rect;
  rect.w = texture_manager->texture_width;
  rect.h = texture_manager->texture_height;
  
  for (int z = 0; z < CHUNK_SIZE; z++){
    for (int y = 0; y < CHUNK_SIZE; y++){
      for (int x = 0; x < CHUNK_SIZE; x++){
        uint8_t tile_id = chunk->tiles[z][y][x];
        if (tile_id == 0) continue;

        SDL_Texture* tile_texture = texturemanager_get_texture(texture_manager, tile_id);
        
        iv.x = x;
        iv.y = y;
        iv.z = z;

        sv = isometric_to_screen(iv, scale);

        rect.x = sv.x;
        rect.y = sv.y;
        
        SDL_RenderCopy(renderer, tile_texture, NULL, &rect);
      }
    }
  }
  
  SDL_SetRenderTarget(renderer, NULL);
  chunk->is_dirty = false;
}

void chunk_destroy_chunk(Chunk* chunk){
  if (!chunk) return;
  SDL_DestroyTexture(chunk->cached_texture);
  free(chunk);
  chunk = NULL;
}
