#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "window.h"
#include "food.h"
#include "snake.h"

#define WIDTH 600
#define HEIGHT 600

int initializeSDL();

void shutdownSDL();

void loop(
    SDL_Renderer* renderer, 
    SDL_Event* event, 
    SDL_Event* savedEvent, 
    Snake* snake, 
    Food* food,
    bool* keyPressed,
    int* running
);

void teleportation(Snake* snake);

#endif
