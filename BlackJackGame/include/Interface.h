#ifndef __INTERFACE_H__
#define __INTERFACE_H__

// #include "All.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

SDL_Event e;
SDL_Window * window;
SDL_Renderer * render = NULL;


bool InicializarSDL();

#endif// _INTERFACE_H_