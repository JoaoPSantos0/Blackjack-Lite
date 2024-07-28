#include "All.h"



Stack * push(Stack * stack, Card *card){
    Node *novo;
    novo = (Node*)malloc(sizeof(Node));
    if(novo == NULL){
        printf("erro no push da pilha\n");
        return NULL;
    }

    card->rect.x = stack->coor_pilha.x;
    card->rect.y = stack->coor_pilha.y;
    novo->c = card;
    novo->anterior = stack->top;
    stack->top = novo;
    stack->tam++;

    card->rect.x = stack->coor_pilha.x;
    card->rect.y = stack->coor_pilha.y;
    card->rect.w = stack->coor_pilha.w;
    card->rect.h = stack->coor_pilha.x;

    return (Stack*)novo;
}

Card * pop(Stack *stack){
    if(stack->tam == 0){
        printf("pilha vazia\n");
        return NULL;
    }

    Node *aux = stack->top;
    Card * remover = aux->c;
    
    stack->top = stack->top->anterior;
    stack->tam--;
    free(aux);

    return (Card*)remover; 
}

void atualizarDeckCompra(){
    if(deck_compra.tam == 0){
        printf("atualizarDeckCompra: stack vazia");
        return;
    }
    int naipe = deck_compra.top->c->naipe;
    int valor = deck_compra.top->c->valor;

    deck_compra.top->c->rect.x = deck_compra.coor_pilha.x;
    deck_compra.top->c->rect.y = deck_compra.coor_pilha.y;
    deck_compra.top->c->rect.w = deck_compra.coor_pilha.w;
    deck_compra.top->c->rect.h = deck_compra.coor_pilha.h;

    SDL_RenderCopy(render, texture_baralho, NULL, &deck_compra.top->c->rect);
}

Card * comprarCarta(Stack *deck){
    Card * aux = pop(deck);
    return aux;
}