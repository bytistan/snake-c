#ifndef SNAKE_H
#define SNAKE_H
   
#include <SDL2/SDL.h>
#include <stdio.h>

#include "color.h"

typedef struct {
    int x;
    int y;
    
    int width;
    int height;

    Color color;
} Snake;

void drawSnake(SDL_Renderer* renderer, Snake snake);

#endif
