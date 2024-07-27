#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "All.h"

typedef struct {
    Card player_cards[2];
    double saldo;
}Player;

SDL_Texture * cartas_player[2];

void receberCartas(Player player, double valor_saldo, Stack * deck);
void dobrarAposta();
void stay();
void dividirAposta();
void load_texture_cartas_player();
void atualizarCartasPlayer();

#endif// _PLAYER_H_