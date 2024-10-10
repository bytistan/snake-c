#include "snake.h"

void drawSnake(SDL_Renderer* renderer, Snake snake) {
    SDL_SetRenderDrawColor(renderer, 
                          snake.color.r, 
                          snake.color.g,
                          snake.color.b,
                          snake.color.a);

    SDL_Rect rect = {
        snake.x + 2,
        snake.y + 2,
        snake.size - 4,
        snake.size - 4 
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
            snake.tail[i].x + 2,
            snake.tail[i].y + 2,
            snake.size - 4,
            snake.size - 4
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

bool updateTail(int score, Snake* snake) {
    int count = 0;

    if (snake->x % snake->size == 0 && snake->y % snake->size == 0) {
        for (int i = 1; i < score + 2; i++) {
            if (i == score + 1) {
                snake->tail[i - 1].x = snake->x;
                snake->tail[i - 1].y = snake->y;
            } else {
                snake->tail[i - 1] = snake->tail[i];
            }

            if (i != score + 1) {
                if (snake->x == snake->tail[i - 1].x && snake->y == snake->tail[i - 1].y) {
                    count ++; 
                } 
            }
        } 
    }
   
    bool flag = true ? count > 0 : false; 

    return flag;
}

void applySpeed(Snake* snake) {
    snake->x += snake->direction.x * snake->speed; 
    snake->y += snake->direction.y * snake->speed;
}

bool moveSnake(SDL_Event event, Snake* snake) {
    if (snake->x % snake->size == 0 && snake->y % snake->size == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:    
                if (snake->direction.x != 0) {
                    snake->direction.x = 0;
                    snake->direction.y = -1;
                }
                break;
            case SDLK_DOWN: 
                if (snake->direction.x != 0) {
                    snake->direction.x = 0;
                    snake->direction.y = 1;
                }
                break;
            case SDLK_LEFT:  
                if (snake->direction.y != 0) {
                    snake->direction.x = -1;
                    snake->direction.y = 0;
                }
                break;
            case SDLK_RIGHT:
                if (snake->direction.y != 0) {
                    snake->direction.x = 1;
                    snake->direction.y = 0;
                }
                break;
        }

        return false;
    }

    return true;
}
