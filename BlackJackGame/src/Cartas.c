#include "All.h"

void embaralhar(Card arr[]){
    srand(time(NULL));
    for(int i = 0; i<TOTAL_CARTAS; i++){
        int swap_index = rand() % TOTAL_CARTAS;
        Card temp = arr[i];
        arr[i] = arr[swap_index];
        arr[swap_index] = temp;
    }
}

void criar_deck(){
    int i = 0, j = 0, cont = 0;
    for(i = 0; i<NAIPE_CARTA; i++){
        for(j = 0; j<TIPOS_CARTAS; j++){
            deck[cont].rect.h = height_card;
            deck[cont].rect.w = width_card;
            deck[cont].turn = true;
            deck[cont].naipe = i;
            deck[cont].valor = j;
            cont++;
        }
    }
    embaralhar(deck);
    
}
void load_texture_deck(){
    texture_baralho = carregarTextura("imagens/Cards/CartaFlopada.png");
}

void atualizarInterface(){
    atualizarCartasDealer();
    atualizarCartasPlayer();
    atualizarDeckCompra();
}


