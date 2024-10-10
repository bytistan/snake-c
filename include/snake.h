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
} Tail;

typedef struct {
    int x;
    int y;
    
    int size;
    int speed;    
    
    Tail tail[400];

    Direction direction;    

    Color color;
} Snake;

void drawSnake(SDL_Renderer* renderer, Snake snake);

void drawTail(SDL_Renderer* renderer, Snake snake, int score);

bool appendTail(int score, Snake* snake);

void updateTail(int score, Snake* snake);

void applySpeed(Snake* snake); 

bool moveSnake(SDL_Event event, Snake* snake);

#endif
