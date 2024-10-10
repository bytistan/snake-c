#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include "game.h"

int main(int argc, char* argv[]) {
    // Start SDL 
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL failed to initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = createWindow("Snake Game", WIDTH, HEIGHT);

    if (window == NULL) {
        printf("[!] Window could not be created!\n");
        return -1;
    }
    
    Food food = {
        .x = 180, 
        .y = 180, 
        .size = 30, 
        .score = 1, 
        .color = {240, 62, 62, 255},
        .flag = false
    };    

    Snake snake = {
        .x = 90, 
        .y = 90, 
        .size = 30, 
        .speed = 5, 
        .direction = {1,0}, 
        .color = {32, 201, 151, 255}
    };

    SDL_Event event;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    int running = 1;    

    bool keyPressed = false;
    SDL_Event savedEvent;

    while (running) {
        // Nearly 60 fps 
        SDL_Delay(16);
        
        // Game loop
        loop(
            renderer, 
            &event, 
            &savedEvent,
            &snake, 
            &food,
            &keyPressed,
            &running
        ); 

        // Update screen
        SDL_RenderPresent(renderer);
    }

    destroyWindow(window);
    return 0;
}
