#include "All.h"

bool InicializarSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    if(TTF_Init()==-1){
        return false;
    }
    window = SDL_CreateWindow("BlackJack", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1700, 900, SDL_WINDOW_SHOWN);
    if(!window){
        printf("Erro %s\n",SDL_GetError());
        SDL_Quit();
        return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(render, 8, 124, 6, 255);
    //SDL_RenderClear(render);
    //SDL_RenderPresent(render);

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

    texture = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);

    return texture;

}

/* void RenderText(const char *text, SDL_Texture* textureFont, SDL_Rect rectFont){
    SDL_Color textColor = {0,0,0};
    snprintf(text, 50, "Saldo: %d",saldoIni);
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    textureFont = SDL_CreateTextureFromSurface(render, textSurface);
    rectFont.w = textSurface->w;
    rectFont.h = textSurface->h;
    rectFont.x = (SCREEN_WIDTH - rectFont.w)/2;

    SDL_FreeSurface(textSurface);
}

void RenderSaldoPlayer(){
    saldoPlayerRect.y = SCREEN_HEIGHT/2 -30;

    RenderText("Saldo:", SaldoPlayer, saldoPlayerRect);
    SDL_RenderCopy(render, SaldoPlayer, NULL, &saldoPlayerRect);
} */


