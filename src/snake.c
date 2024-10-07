#include "snake.h"

void drawSnake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 
                          snake.color.r, 
                          snake.color.g,
                          snake.color.b,
                          snake.color.a);

    SDL_Rect rect = {snake.x,snake.y,snake.size,snake.size};
    SDL_RenderFillRect(renderer, &rect);
}

void applySpeed(Snake* snake) {
    snake->x += snake->direction.x * snake->speed; 
    snake->y += snake->direction.y * snake->speed;
}

bool moveSnake(SDL_Event event, Snake* snake) {
    if (snake->x % snake->size == 0 && snake->y % snake->size == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:    
                snake->direction.x = 0;
                snake->direction.y = -1;
                break;
            case SDLK_DOWN: 
                snake->direction.x = 0;
                snake->direction.y = 1;
                break;
            case SDLK_LEFT:  
                snake->direction.x = -1;
                snake->direction.y = 0;
                break;
            case SDLK_RIGHT:
                snake->direction.x = 1;
                snake->direction.y = 0;
                break;
        }

        return false;
    }

    return true;

}
