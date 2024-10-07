#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

SDL_Window* createWindow(const char* title, int width, int height);

void destroyWindow(SDL_Window* window);

#endif

