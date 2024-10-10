#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "window.h"
#include "food.h"
#include "snake.h"

#define WIDTH 400
#define HEIGHT 400

int initializeSDL();

void shutdownSDL();
void loop(SDL_Renderer* renderer, SDL_Event event, Snake* snake, Food* food);

void teleportation(Snake* snake);

#endif
