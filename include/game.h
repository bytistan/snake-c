#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>

#include "window.h"
#include "snake.h"

int initializeSDL();

void shutdownSDL();
void loop(SDL_Renderer* renderer, SDL_Event event, Snake* snake);

void input(SDL_Event evetn, Snake* snake);

#endif
