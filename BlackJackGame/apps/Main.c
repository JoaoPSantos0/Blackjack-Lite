#include "All.h"


//SDL_Rect algo;
//SDL_Texture* textura = carregar_textura("img.png");
//SDL_RenderCopy(renderer, textura, NULL, &algo);

void carregarGame(){//inicializar as texturas;
    //distancias do deck de compra;
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
    //distancia da cartas do player;

    const int border_distanceX = 700;
    const int border_distanceY = 700;
    int X1 = border_distanceX;
    int Y1 = border_distanceY;


    for(int i = 0; i<2; i++){
        cartasPlayer[i].h = height_card;
        cartasPlayer[i].w = width_card;
        cartasPlayer[i].x = X1;
        cartasPlayer[i].y = Y1;
        X1 += width_card + 20;
    }
    //distancias do dealer;
    const int dist_borderX = 700;
    const int dist_borderY = 200;
    int cX = dist_borderX;
    int cY = dist_borderY;

    load_texture_deck();
    load_texture_cartas_dealer();
    load_texture_cartas_player();
    criar_deck();

    deck_compra.coor_pilha.x = 10; 
    deck_compra.coor_pilha.y = 10; 
    deck_compra.coor_pilha.w = width_card; 
    deck_compra.coor_pilha.h = height_card; 
    for(int i = 0; i < TOTAL_CARTAS; i++){ 
        push(&deck_compra, &deck[i]); 
    } 
    deck_compra.coor_pilha.x = deckCompra.x;
    deck_compra.coor_pilha.y = deckCompra.y;
    deck_compra.coor_pilha.w = deckCompra.w;
    deck_compra.coor_pilha.h = deckCompra.h;

    receberCartas(&player, &deck_compra); 

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