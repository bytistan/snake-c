#include "game.h"
#include "snake.h"

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

void loop(SDL_Renderer* renderer, SDL_Event event, Snake snake) {
    
    int running = 1;    

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
               running = 0;
            } 
        } 

        // Fill screen to black
        SDL_SetRenderDrawColor(renderer, 33, 37, 41, 255);
        SDL_RenderClear(renderer);
        
        // Draw snake
        drawSnake(renderer, snake);

        // Update screen
        SDL_RenderPresent(renderer);
        
        // Nearly 60 fps 
        SDL_Delay(16);
    }
    
}
