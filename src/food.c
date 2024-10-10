#include "food.h"

void drawFood(SDL_Renderer* renderer, Food food) {
    SDL_SetRenderDrawColor(renderer, 
                          food.color.r, 
                          food.color.g,
                          food.color.b,
                          food.color.a);

    SDL_Rect rect = {food.x,food.y,food.size,food.size};
    SDL_RenderFillRect(renderer, &rect);
}

void eatFood(Food* food, Snake snake) {
    if (food->x == snake.x && food->y == snake.y) {
        srand(time(NULL));

        int x = (rand() % 20) * 20; 
        int y = (rand() % 20) * 20;

        food->x = x;
        food->y = y;

        food->score += 1;
        food->flag = true;
    }
}
