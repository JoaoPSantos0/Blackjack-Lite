#ifndef __INTERFACE_H__
#define __INTERFACE_H__

//#include "All.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

SDL_Event e;
SDL_Window * window;
SDL_Renderer * render = NULL;
SDL_Texture* background_texture = NULL;

SDL_Rect background_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};


bool InicializarSDL();

SDL_Texture* carregarTextura(const char* image_path);

bool is_clicking_on_rect(SDL_Rect* r);

//--------------------Fontes-----------------------

const char * FONT_PATH = "Fonte/ChrustyRock-ORLA.ttf";
const int FONT_SIZE = 28;

char text[50];
int saldoIni = 1000;

TTF_Font * font = NULL;

void RenderText(const char *text, SDL_Texture* textureFont, SDL_Rect rectFont);

#endif// _INTERFACE_H_