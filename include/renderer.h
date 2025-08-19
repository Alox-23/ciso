#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "player.h"
#include "texturemanager.h"
#include "chunk.h"

typedef struct{
  double scale_2d;
  int width;
  int height;
  SDL_Renderer *sdl_renderer;
  SDL_Window *window; 
  TextureManager* texture_manager;
  Chunk chunk;
}Renderer;

Renderer* renderer_create();
void renderer_render_player_2d(Renderer *renderer, Player *player);
void renderer_render_map_iso(Renderer *renderer);
void renderer_render(Renderer *renderer, Player *player);
void renderer_destroy(Renderer *renderer);

#endif
