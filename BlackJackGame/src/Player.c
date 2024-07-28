#include "Player.h"

void receberCartas(Player *p, Stack *deck){
    for(int i = 0; i<2; i++){
        Card *aux = pop(deck);
        p->player_cards[i].naipe = aux->naipe;
        p->player_cards[i].turn = aux->turn;
        p->player_cards[i].valor = aux->valor;
        p->player_cards[i].rect.x = aux->rect.x;
        p->player_cards[i].rect.y = aux->rect.y;
        p->player_cards[i].rect.h = aux->rect.h;
        p->player_cards[i].rect.w = aux->rect.w;
    }
}
void receberCartasDealer(Player *p, Stack *deck){
    for(int i = 0; i<2; i++){
        Card *aux = pop(deck);
        p->player_cards[i].naipe = aux->naipe;
        if(i == 1){
            p->player_cards[i].turn = aux->turn;
            }
        p->player_cards[i].valor = aux->valor;
        p->player_cards[i].rect.x = aux->rect.x;
        p->player_cards[i].rect.y = aux->rect.y;
        p->player_cards[i].rect.h = aux->rect.h;
        p->player_cards[i].rect.w = aux->rect.w;
    }
}



void load_texture_cartas_player(){
    for(int i = 0; i < NAIPE_CARTA; i++){
        for(int j = 1; j <= TIPOS_CARTAS; j++){
            texture_cards[i][j] = carregarTextura(caminho_imagens[i][j]);
        }
    }
}

void atualizarCartasPlayer(){

    for(int i = 0; i<2; i++){
        player.player_cards[i].rect.x = cartasPlayer[i].x;
        player.player_cards[i].rect.y = cartasPlayer[i].y;
        player.player_cards[i].rect.w = cartasPlayer[i].w;
        player.player_cards[i].rect.h = cartasPlayer[i].h;

        int naipe = player.player_cards[i].naipe;
        int valor = player.player_cards[i].valor;
        if(player.player_cards[i].turn ){
            SDL_RenderCopy(render, texture_baralho, NULL, &player.player_cards[i].rect);
        }
        SDL_RenderCopy(render, texture_cards[naipe][valor], NULL, &player.player_cards[i].rect);
    }
}
void atualizarCartasDealer(){

    for(int i = 0; i<2; i++){
        dealer.player_cards[i].rect.x = cartasDealer[i].x;
        dealer.player_cards[i].rect.y = cartasDealer[i].y;
        dealer.player_cards[i].rect.w = cartasDealer[i].w;
        dealer.player_cards[i].rect.h = cartasDealer[i].h;

        int naipe = dealer.player_cards[i].naipe;
        int valor = dealer.player_cards[i].valor;
        if(dealer.player_cards[i].turn ){
            SDL_RenderCopy(render, texture_baralho, NULL, &dealer.player_cards[i].rect);
        }
        else{
        SDL_RenderCopy(render, texture_cards[naipe][valor], NULL, &dealer.player_cards[i].rect);
        }
    }
}