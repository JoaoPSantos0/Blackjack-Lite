#include "All.h"


//SDL_Rect algo;
//SDL_Texture* textura = carregar_textura("img.png");
//SDL_RenderCopy(renderer, textura, NULL, &algo);

void carregarGame(){//inicializar as texturas;

    const int border_distance_x = 20;
    const int border_distance_y = 350;
    const int distance_between_cards_y = 10;
    const int distance_between_cards_x = 30;

    int y = border_distance_y;
    int x = border_distance_x;
    int i = 0;

    deckCompra.w = width_card;
    deckCompra.h = height_card;
    deckCompra.x = x;
    deckCompra.y = y;
    load_texture_deck();
    load_texture_cartas_player();
    criar_deck();
}


int main(){

    bool quit = false;

    if(!InicializarSDL()){
        return 1;
    }
    carregarGame();
    
    while(!quit){
        SDL_SetRenderDrawColor(render, 8, 124, 6, 255);
        SDL_RenderClear(render);
       // SDL_RenderPresent(render);
        atualizarInterface();
        
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(3);
    }
    SDL_Quit();
}