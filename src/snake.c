#include "snake.h"

void drawSnake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 
                          snake.color.r, 
                          snake.color.g,
                          snake.color.b,
                          snake.color.a);

    SDL_Rect rect = {snake.x,snake.y,snake.width,snake.height};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void applySpeed(Snake* snake) {
    snake->x += snake->direction.x * snake->speed; 
    snake->y += snake->direction.y * snake->speed;
}
