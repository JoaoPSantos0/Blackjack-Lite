#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "All.h"

typedef struct {
    Card player_cards[2];
    double saldo;
    int tam;
    int soma;
}Player;

SDL_Texture * cartas_player[2];

Player player;

Player dealer;

void receberCartas(Player *player, Stack * deck);
void receberCartasDealer(Player *p, Stack *deck);
void dobrarAposta();
int somaCartas(Player* play);
void load_texture_cartas_player();
void atualizarCartasPlayer();
void atualizarCartasDealer();

void comprarCartaPlayer();
void comprarCartaDealer();

void dealer_action();

#endif// _PLAYER_H_