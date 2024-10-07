#include "game.h"
#include "snake.h"
#include "food.h"

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

void loop(SDL_Renderer* renderer, SDL_Event event, Snake* snake, Food* food) {
    
    int running = 1;    

    bool keyPressed = false;
    SDL_Event savedEvent;

    while (running) {
        // Nearly 60 fps 
        SDL_Delay(16);

        // Add speed to snake
        applySpeed(snake);    

        // Check snake eat the food ?
        eatFood(food,*snake); 
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
               running = 0;
            } 
            
            // Check key down 
            if (event.type == SDL_KEYDOWN) {
                keyPressed = true;
                savedEvent = event;
            } 
        } 
        
        // Movement controller
        if (keyPressed) {
            keyPressed = moveSnake(savedEvent, snake);
        }

        // Fill screen to black
        SDL_SetRenderDrawColor(renderer, 33, 37, 41, 255);
        SDL_RenderClear(renderer);
        
        // Draw sprite 
        drawSnake(renderer, *snake);
        drawFood(renderer, *food);

        // Update screen
        SDL_RenderPresent(renderer);
    }
}

void teleportation(Snake* snake) {
   if (snake->x > WIDTH) {
       snake->x = 0;
   } else if(snake->x < 0) {
       snake->x = WIDTH;
   } else if (snake->y > HEIGHT) {
       snake->y = 0; 
   } else if (snake->y < 0) {
       snake-> y = HEIGHT;
   }
}
