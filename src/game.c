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

void loop(SDL_Renderer* renderer, SDL_Event event, Snake* snake) {
    
    int running = 1;    

    while (running) {
        // Nearly 60 fps 
        SDL_Delay(16);

        // Add speed to snake
        applySpeed(snake);    
    
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
               running = 0;
            } 
            
            if (event.type == SDL_KEYDOWN) {
                input(event, snake);
            } 
        } 
                    
        // Fill screen to black
        SDL_SetRenderDrawColor(renderer, 33, 37, 41, 255);
        SDL_RenderClear(renderer);
        
        // Draw snake
        drawSnake(renderer, *snake);

        // Update screen
        SDL_RenderPresent(renderer);
    }
}

void input(SDL_Event event, Snake* snake) {
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
}
