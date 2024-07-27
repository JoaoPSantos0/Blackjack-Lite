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
