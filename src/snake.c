#include "snake.h"

void drawSnake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 
                          snake.color.r, 
                          snake.color.g,
                          snake.color.b,
                          snake.color.a);

    SDL_Rect rect = {
        snake.x + 1,
        snake.y + 1,
        snake.size - 2,
        snake.size - 2
    };

    SDL_RenderFillRect(renderer, &rect);
}

void drawTail(SDL_Renderer* renderer, Snake snake, int score) {
    for (int i = 0; i < score + 1; i++) {
        SDL_SetRenderDrawColor(renderer, 
                              snake.color.r, 
                              snake.color.g,
                              snake.color.b,
                              snake.color.a);
        
        SDL_Rect rect = {
            snake.tail[i].x + 1,
            snake.tail[i].y + 1,
            snake.size - 2,
            snake.size - 2
        };

        SDL_RenderFillRect(renderer, &rect);
    } 
}

bool appendTail(int score, Snake* snake) {
    if (snake->x % snake->size != 0 && snake->y % snake->size != 0) {
        return true;
    }

    snake->tail[score].x = snake->x;
    snake->tail[score].y = snake->y;
    
    return false;
}

void updateTail(int score, Snake* snake) {
    if (snake->x % snake->size == 0 && snake->y % snake->size == 0) {
        for (int i = 1; i < score + 2; i++) {
            if (i == score + 1) {
                snake->tail[i - 1].x = snake->x;
                snake->tail[i - 1].y = snake->y;
            } else {
                snake->tail[i - 1] = snake->tail[i];
            }
        }
    } 
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
