#ifndef _DEALER_H_
#define _DEALER_H_

#include "All.h"

typedef struct{
    Card dealer_cards[2];
    int soma;
}Dealer;

SDL_Texture * cartas_dealer[2];


Dealer dealer;

void receberCartasDealer(Dealer *p, Stack *deck);

void load_texture_cartas_dealer();

void atualizarCartasDealer();

#endif//_DEALER_H_