#include "window.h"
#include <stdio.h>

SDL_Window* createWindow(const char* title, int width, int height) {

    SDL_Window* window = SDL_CreateWindow(title,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("[!] Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(window);
        return NULL;
    }

    return window;
}

void destroyWindow(SDL_Window* window) {
    if (window) {
        SDL_DestroyWindow(window);
    }
}

