#include "Dealer.h"


void receberCartasDealer(Dealer *d, Stack *deck){
    for(int i = 0; i<2; i++){
        Card *aux = pop(deck);
        d->dealer_cards[i].naipe = aux->naipe;
        d->dealer_cards[i].turn = aux->turn;
        d->dealer_cards[i].valor = aux->valor;
        d->dealer_cards[i].rect.x = aux->rect.x;
        d->dealer_cards[i].rect.y = aux->rect.y;
        d->dealer_cards[i].rect.h = aux->rect.h;
        d->dealer_cards[i].rect.w = aux->rect.w;
    }
}

void load_texture_cartas_dealer(){
    for(int i = 0; i < NAIPE_CARTA; i++){
        for(int j = 1; j <= TIPOS_CARTAS; j++){
            texture_cards[i][j] = carregarTextura(caminho_imagens[i][j]);
        }
    }
}


void atualizarCartasDealer(){

    for(int i = 0; i<2; i++){
        dealer.dealer_cards[i].rect.x = cartasDealer[i].x;
        dealer.dealer_cards[i].rect.y = cartasDealer[i].y;
        dealer.dealer_cards[i].rect.w = cartasDealer[i].w;
        dealer.dealer_cards[i].rect.h = cartasDealer[i].h;

        int naipe = dealer.dealer_cards[i].naipe;
        int valor = dealer.dealer_cards[i].valor;
        SDL_RenderCopy(render, texture_cards[naipe][valor], NULL, &dealer.dealer_cards[i].rect);
    }
}