#include "Player.h"


void receberCartas(Player *p, Stack *deck){
    for(int i = 0; i<2; i++){
        Card *aux = pop(deck);
        p->player_cards[i].numero = aux->numero;
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
        p->player_cards[i].numero = aux->numero;
        p->player_cards[i].valor = aux->valor;
        p->player_cards[i].rect.x = aux->rect.x;
        p->player_cards[i].rect.y = aux->rect.y;
        p->player_cards[i].rect.h = aux->rect.h;
        p->player_cards[i].rect.w = aux->rect.w;
    }
    p->soma = p->player_cards[0].valor + p->player_cards[0].valor;
}



void load_texture_cartas_player(){
    for(int i = 0; i < NAIPE_CARTA; i++){
        for(int j = 1; j <= TIPOS_CARTAS; j++){
            texture_cards[i][j] = carregarTextura(caminho_imagens[i][j]);
        }
    }
}

void atualizarCartasPlayer(){

    for(int i = 0; i<3; i++){
        if(animacao2 && i == 2) break;
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

    for(int i = 0; i<3; i++){
        if(animacao && i == 2) break;
        dealer.player_cards[i].rect.x = cartasDealer[i].x;
        dealer.player_cards[i].rect.y = cartasDealer[i].y;
        dealer.player_cards[i].rect.w = cartasDealer[i].w;
        dealer.player_cards[i].rect.h = cartasDealer[i].h;

        int naipe = dealer.player_cards[i].naipe;
        int valor = dealer.player_cards[i].valor;
        if(valor == 0) continue;
        if(dealer.player_cards[i].turn ){
            SDL_RenderCopy(render, texture_baralho, NULL, &dealer.player_cards[i].rect);
        }
        else{
        SDL_RenderCopy(render, texture_cards[naipe][valor], NULL, &dealer.player_cards[i].rect);
        }
    }
}

int somaCartas(Player* play){    
    play->soma = play->player_cards[0].numero + play->player_cards[1].numero + play->player_cards[2].numero;
    for(int j = 0; j<3; j++){
        if(play->player_cards[j].valor == 1 && play->soma >21){
            play->soma -= 10;
        }
            
    }
    int soma = play->soma;
    return soma;
}

void comprarCartaPlayer(){
    Card* c = comprarCarta(&deck_compra);
    animacao2 = true;
    player.player_cards[2].naipe = c->naipe;
    player.player_cards[2].numero = c->numero;
    player.player_cards[2].valor = c->valor;
    player.player_cards[2].turn = false;
}

void comprarCartaDealer(){
    Card* c = comprarCarta(&deck_compra);
    animacao = true;
    dealer.player_cards[2].naipe = c->naipe;
    dealer.player_cards[2].numero = c->numero;
    dealer.player_cards[2].valor = c->valor;
    dealer.player_cards[2].turn = false;
}

void dealer_action(){    
    if(somaCartas(&dealer) >= 16){
        return;
    }
    if(somaCartas(&dealer) <= 11){
        comprarCartaDealer();
        return;
    }

    int aleatorio = rand() % 2;
    if(aleatorio % 2 == 0){
        comprarCartaDealer();
    }

}

bool animacaoDealer(){
    if(carta_animacao.x < dealer.player_cards[2].rect.x){
        carta_animacao.x++;
        return false;
    }

    if(carta_animacao.y > dealer.player_cards[2].rect.y){
        carta_animacao.y--;
        return false;
    }


    return true;
}

bool animacaoPlayer(){
    if(carta_animacao_player.x < player.player_cards[2].rect.x){
        carta_animacao_player.x++;
        return false;
    }

    if(carta_animacao_player.y < player.player_cards[2].rect.y){
        carta_animacao_player.y++;
        return false;
    }

    return true;
}