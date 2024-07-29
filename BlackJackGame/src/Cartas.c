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
        for(j = 1; j<=TIPOS_CARTAS; j++){
            deck[cont].rect.h = height_card;
            deck[cont].rect.w = width_card;
            deck[cont].turn = true;
            deck[cont].naipe = i;
            deck[cont].valor = j;
            if(j>=10){
                deck[cont].numero = 10;
            }
            else if(j==1){
                deck[cont].numero = 11;
            }
            else{
                deck[cont].numero = j;
            }
            
            cont++;
        }
    }
    embaralhar(deck);
    
}
void load_texture_bot(){
    botao_Comprar = carregarTextura("imagens/Background/botCompra.png");
    botao_Manter = carregarTextura("imagens/Background/botManter.png");
}

void load_texture_empate(){
    empate_texture = carregarTextura("imagens/Background/empate.png");
}

void atualizarBotoes(){
    SDL_RenderCopy(render, botao_Comprar, NULL, &botaoCompra);
    SDL_RenderCopy(render, botao_Manter, NULL, &botaoManter);
}
void load_texture_deck(){
    texture_baralho = carregarTextura("imagens/Cards/CartaFlopada.png");
}

void atualizarInterface(){
    atualizarCartasDealer();
    atualizarCartasPlayer();
    atualizarBotoes();
    atualizarDeckCompra();
    
}

void load_texture_lose(){
    youLose = carregarTextura("imagens/Background/Youlose.png");
    playAgain = carregarTextura("imagens/Background/playagain.png");
}
void load_texture_win(){
    youWin = carregarTextura("imagens/Background/youwin.png");
    playAgain = carregarTextura("imagens/Background/playagain.png");
}

void atualizar_tela_perdeu(){
    SDL_RenderCopy(render, youLose, NULL, &you_lose);
    SDL_RenderCopy(render, playAgain, NULL, &play_again);
}

void atualizar_tela_ganhou(){
    SDL_RenderCopy(render, youWin, NULL, &you_win);
    SDL_RenderCopy(render, playAgain, NULL, &play_again);
    
}

void atualizar_tela_empate(){
    SDL_RenderCopy(render, empate_texture, NULL, &empate_rect);
    SDL_RenderCopy(render, playAgain, NULL, &play_again);
}
 
void zerar_carta_animacao(){
    carta_animacao.x = deck_compra.coor_pilha.x;
    carta_animacao.y = deck_compra.coor_pilha.y;
    animacao = false;
}

void zerar_carta_animacao2(){
    carta_animacao_player.x = deck_compra.coor_pilha.x;
    carta_animacao_player.y = deck_compra.coor_pilha.y;
    animacao2 = false;
}
