#include "food.h"

void drawFood(SDL_Renderer* renderer, Food food) {
    SDL_SetRenderDrawColor(renderer, 
                          food.color.r, 
                          food.color.g,
                          food.color.b,
                          food.color.a);

    SDL_Rect rect = {
        food.x + 1,
        food.y + 1,
        food.size - 2,
        food.size - 2
    };

    SDL_RenderFillRect(renderer, &rect);
}

void eatFood(Food* food, Snake snake) {
    if (food->x == snake.x && food->y == snake.y) {
        srand(time(NULL));

        int x = (rand() % 20) * 30; 
        int y = (rand() % 20) * 30;

        food->x = x;
        food->y = y;

        food->score += 1;
        food->flag = true;
    }
}
