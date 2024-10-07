#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include "window.h"
#include "game.h"
#include "snake.h" 
#include "food.h"

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
    
    Food food = {200, 200, 20, {240, 62, 62, 255}};    
    Snake snake = {100, 100, 20, 4, {0,0}, {32, 201, 151, 255}};

    SDL_Event event;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    loop(renderer, event, &snake, &food); 

    destroyWindow(window);
    return 0;
}
