#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "renderer.h"
#include "player.h"
#include "world.h"

typedef struct{
  Player *player;
  Renderer *renderer;
  World* world;
  const Uint8 *keystate;
  double delta_time;
  int state;
}Game;

void game_destroy(Game *game, int exit_status);
void game_update(Game *game);
Game* game_create(); 

#endif
