#include "game.h"

int initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("[!] SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

void shutdownSDL() {
    SDL_Quit();
}

void loop(
    SDL_Renderer* renderer, 

    SDL_Event* event, 
    SDL_Event* savedEvent,

    Snake* snake, 
    Food* food,

    bool* keyPressed,
    int* running
) {
    // Add speed to snake
    applySpeed(snake);    

    // Check snake eat the food ?
    if (!food->flag) {
        eatFood(food,*snake); 
    }
    
    // Update tail positions
    bool game_over = updateTail(food->score, snake); 
        
    if (game_over && !food->flag) {
        * running = 0;
    }

    // If snake eat food, add tail ++ 
    if (food->flag) {
        food->flag = appendTail(food->score,snake);
    }

    // Teleport
    teleportation(snake);
    
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
           * running = 0;
        } 
        
        // Check key down 
        if (event->type == SDL_KEYDOWN) {
            bool flag = true; 
            * keyPressed = &flag;
            
            * savedEvent = *event;
        } 
    } 
    
    // Movement controller
    if (keyPressed) {
        if (snake->x >= 0 && snake->x <= WIDTH - snake->size && snake->y >=0 && snake->y <= HEIGHT - snake->size) {
            bool flag = moveSnake(*savedEvent, snake);
            * keyPressed = &flag;  
        }
    }

    // Fill screen to black
    SDL_SetRenderDrawColor(renderer, 33, 37, 41, 255);
    SDL_RenderClear(renderer);
    
    // Draw sprite 
    drawSnake(renderer, *snake);
    drawTail(renderer, *snake, food->score);
    drawFood(renderer, *food);
}

void teleportation(Snake* snake) {
   if (snake->x >= WIDTH) {
       snake->x = -snake->size;
   } else if(snake->x <= -snake->size) {
       snake->x = WIDTH;
   } else if (snake->y >= HEIGHT) {
       snake->y = -snake->size; 
   } else if (snake->y <= -snake->size) {
       snake->y = HEIGHT;
   }
}
