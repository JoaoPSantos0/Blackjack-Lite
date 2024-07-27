#include "All.h"

bool InicializarSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("BlackJack", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1700, 900, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Erro %s\n",SDL_GetError());
        SDL_Quit();
        return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(render, 8, 124, 6, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    if(!render){
        printf("Erro %s\n",SDL_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}

SDL_Texture* carregarTextura(const char* image_path){
    SDL_Texture* texture = NULL;

    SDL_Surface* surface = IMG_Load(image_path);

    if(!surface){
        printf("load_image_to_texture error: %s\n", IMG_GetError());
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);

    return texture;

}


