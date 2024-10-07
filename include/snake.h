#ifndef SNAKE_H
#define SNAKE_H
   
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#include "color.h"

typedef struct {
    int x;
    int y;
} Direction;

typedef struct {
    int x;
    int y;
    
    int size;
    int speed;    

    Direction direction;    

    Color color;
} Snake;

void drawSnake(SDL_Renderer* renderer, Snake snake);

void applySpeed(Snake* snake); 

bool moveSnake(SDL_Event event, Snake* snake);

#endif
