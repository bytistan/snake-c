#include <SDL2/SDL.h>

#include "window.h"
#include "game.h"
#include "snake.h" 

int main(int argc, char* argv[]) {
    SDL_Window* window = createWindow("Snake Game", 400, 400);

    if (window == NULL) {
        printf("[!] Window could not be created!\n");
        return -1;
    }
    
    Snake snake = {100,100,20,20,{32, 201, 151, 255}};

    SDL_Event event;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    loop(renderer, event, snake); 

    destroyWindow(window);
    return 0;
}

