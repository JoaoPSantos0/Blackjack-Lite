#include "All.h"

bool InicializarSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("BlackJack", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Erro %s\n",SDL_GetError());
        SDL_Quit();
        return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!render){
        printf("Erro %s\n",SDL_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}