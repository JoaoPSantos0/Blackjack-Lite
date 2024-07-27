#include "Player.h"

void receberCartas(Player p, double valor_saldo, Stack *deck){
    for(int i = 0; i<2; i++){
        Card *aux = pop(deck);
        p.player_cards[i].naipe = aux->naipe;
        p.player_cards[i].turn = aux->turn;
        p.player_cards[i].valor = aux->valor;
        p.player_cards[i].rect.x = aux->rect.x;
        p.player_cards[i].rect.y = aux->rect.y;
        p.player_cards[i].rect.h = aux->rect.h;
        p.player_cards[i].rect.w = aux->rect.w;
    }
}



void load_texture_cartas_player(){
    for(int i = 0; i<2; i++){
        texture_player_cards[i] = carregarTextura(caminho_imagens);
    }
}

void atualizarCartasPlayer(){
    for(int i = 0; i<2; i++){
        SDL_RenderCopy(render,texture_player_cards[i], NULL, &cartasPlayer[i]);
    }
}