#ifndef _STACK_H_
#define _STACK_H_

#include "Cartas.h"

typedef struct _node{
    Card * c;
    struct _node * anterior;
}Node;

typedef struct{
    int tam;
    Node *top;
    SDL_Rect coor_pilha;
} Stack;

Stack deck_compra;


void renderizar();

Stack * push(Stack * stack, Card *card);
Card * pop(Stack * stack);

Card * comprarCarta(Stack * deck);
void atualizarDeckCompra();

#endif