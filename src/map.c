#include "../include/map.h"
#include <stdio.h>

//impure function that create a contiguous array of size width * height modifies a maps buffer array probably declared in main.c
Map* map_create(size_t width, size_t height){
  Map* map = malloc(sizeof(Map));  
  if (map == NULL || width == 0 || height == 0){
    return NULL;
  }
   
  map->buffer = malloc(sizeof(int) * height * width); 
  if (!map->buffer){
    return NULL;
  }
  
  map->height = height;
  map->width = width;

  for (size_t y = 0; y < map->height; y++){
    for (size_t x = 0; x < map->width; x++){
      map_set_value(map, x, y, 1);
    } 
  }
   
  return map;
}

int map_get_value(Map *map, size_t x, size_t y){
  if (map == NULL || x >= map->width || y >= map->height){
    return 0;
  }
  return map->buffer[y * map->width + x];
}

void map_set_value(Map *map, size_t x, size_t y, int value){
  if (map == NULL || x >= map->width || y >= map->height){
    return;
  }
  map->buffer[y * map->width + x] = value;
}

void map_destroy(Map *map){
  if (!map){
    return;
  }

  free(map->buffer);
  map->buffer = NULL;
  free(map);
  map = NULL;
}
