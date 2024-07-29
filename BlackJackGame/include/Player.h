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

bool animacao = true;
bool animacao2 = true;
SDL_Rect carta_animacao = {0, 0, width_card, height_card};
SDL_Rect carta_animacao_player = {0, 0, width_card, height_card};;

void receberCartas(Player *player, Stack * deck);
void receberCartasDealer(Player *p, Stack *deck);
void dobrarAposta();
int somaCartas(Player* play);
void load_texture_cartas_player();
void atualizarCartasPlayer();
void atualizarCartasDealer();

void comprarCartaPlayer();
void comprarCartaDealer();
bool animacaoDealer();
bool animacaoPlayer();

void dealer_action();

#endif// _PLAYER_H_