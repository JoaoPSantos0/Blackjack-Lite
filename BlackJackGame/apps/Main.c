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
    const int dist_borderY = 85;
    int cX = dist_borderX;
    int cY = dist_borderY;
    for(int j = 0; j<2; j++){
        cartasDealer[j].h = height_card;
        cartasDealer[j].w = width_card;
        cartasDealer[j].x = cX;
        cartasDealer[j].y = cY;
        cX += width_card + 20;
    }
    //Distancia botoes
    const int dis_botX = 500;
    const int dis_botY = 300;
    int bX = dis_botX;
    int bY = dis_botY;
    botaoCompra.h = 400;
    botaoCompra.w = 500;
    botaoCompra.x = bX;
    botaoCompra.y = bY;

    botaoManter.h = 400;
    botaoManter.w = 500;
    botaoManter.x = bX +200;
    botaoManter.y = bY;

    //Tela de vc perdeu

    you_lose.h = 900;
    you_lose.w = 900;
    you_lose.x = 1000;
    you_lose.y = 100;

    play_again.h = 600;
    play_again.w = 600;
    play_again.x = 1000;
    play_again.y = 400;

    you_win.h = 900;
    you_win.w = 900;
    you_win.x = 1000;
    you_win.y = 100;
    
    /* //Carregar texto saldo
    saldoPlayerRect.h = 300;
    saldoPlayerRect.w = 100;
    saldoPlayerRect.x = X1 + 200;
    saldoPlayerRect.y = Y1; */
    load_texture_lose();
    load_texture_win();
    load_texture_bot();
    load_texture_deck();
    load_texture_cartas_player();
    criar_deck();
    //Coordenada do deck de compra;
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
    receberCartasDealer(&dealer, &deck_compra);
    receberCartas(&player, &deck_compra); 
    printf("%d\n", somaCartas(player));
    printf("%d\n", somaCartasDealer(dealer));

}


int main(){

    bool quit = false;

    if(!InicializarSDL()){
        return 1;
    }
    carregarGame();
    

    bool ganhou = false;
    bool perdeu = false;
    while(!quit){
        SDL_SetRenderDrawColor(render, 8, 124, 6, 255);
        SDL_RenderClear(render);
        
        //atualizarInterface();

        while(SDL_PollEvent(&e) != 0){
            SDL_GetMouseState(&mouseX, &mouseY);
            if(e.type == SDL_QUIT){
                quit = true;
            }
            
            if(SDL_MOUSEBUTTONDOWN == e.type){
                clicked = true;
                //printf("Cliquei\n");
            }
        }
        atualizarInterface();
        if(clicked){
            cliqueiManter();

            
            if(somaCartas(player)>somaCartasDealer(dealer) && somaCartas(player)<=21){
                ganhou = true;
            }
            else if(somaCartas(player)<somaCartasDealer(dealer) && somaCartasDealer(dealer)>21){
                ganhou = true;
            }
            else{
                perdeu = true;
            }
                clicked = false;
        }
        if(ganhou){
            atualizar_tela_ganhou();
        }
        else if(perdeu){
            atualizar_tela_perdeu;
        }
        if(clicked){
            if(clicandoPlayAgain()){
                carregarGame();
                printf("Ta clicando\n");
            }
        }

        SDL_RenderPresent(render);
        SDL_Delay(3);
    }
    SDL_Quit();
}