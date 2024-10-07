#ifndef FOOD_H
#define FOOD_H
   
#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>

#include "color.h"
#include "snake.h"

typedef struct {
    int x;
    int y;
    
    int size;
    
    Color color;
} Food;

void drawFood(SDL_Renderer* renderer, Food food);

void changeFoodPos(Food* food); 

void eatFood(Food* food, Snake snake);

#endif
