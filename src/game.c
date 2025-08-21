#include "../include/game.h"
#include "../include/player.h"
#include "../include/world.h"

Game* game_create(){
  Game* game = malloc(sizeof(Game));
  if (!game) return NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING)) return NULL;  
 
  game->renderer = renderer_create();
  if (!game->renderer) return NULL;

  game->player = player_create();
  if (!game->player) return NULL;

  game->world = world_create(5, 5, 5);
  if (!game->world) return NULL;

  game->keystate = SDL_GetKeyboardState(NULL);
  
  game->state = 1;
  game->delta_time = 1;

  return game;
}

void game_update(Game *game){
  player_update(game->player, game->delta_time);
}

void game_destroy(Game *game, int exit_status){
  if (!game){
    return;
  }

  player_destroy(game->player);
  renderer_destroy(game->renderer);
  world_destroy(game->world);
  free(game);
  game = NULL;
  SDL_Quit();
  exit(exit_status);
}
