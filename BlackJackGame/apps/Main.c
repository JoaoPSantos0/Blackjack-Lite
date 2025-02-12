#include "All.h"

void new_game(){
    embaralhar(deck);
    deletar_pilha(&deck_compra);
    for(int i = 0; i < TOTAL_CARTAS; i++){ 
        push(&deck_compra, &deck[i]); 
    } 
    
    receberCartasDealer(&dealer, &deck_compra);
    receberCartas(&player, &deck_compra); 
    player.player_cards[2].naipe = dealer.player_cards[2].naipe = 0;
    player.player_cards[2].valor = dealer.player_cards[2].valor = 0;
    player.player_cards[2].numero = dealer.player_cards[2].numero = 0;
    zerar_carta_animacao();
    zerar_carta_animacao2();
}

void carregarGame(){//inicializar as texturas;
    //distancias do deck de compra;
    const int border_distance_x = 20;
    const int border_distance_y = 350;
    const int distance_between_cards_y = 10;
    const int distance_between_cards_x = 30;

    int y = border_distance_y;
    int x = border_distance_x;
    int i = 0;

    deckCompra.w = width_card;
    deckCompra.h = height_card;
    deckCompra.x = x;
    deckCompra.y = y;
    //distancia da cartas do player;

    const int border_distanceX = 700;
    const int border_distanceY = 700;
    int X1 = border_distanceX;
    int Y1 = border_distanceY;


    for(int i = 0; i<3; i++){
        cartasPlayer[i].h = height_card;
        cartasPlayer[i].w = width_card;
        cartasPlayer[i].x = X1;
        cartasPlayer[i].y = Y1;
        X1 += width_card + 20;
    }
    //distancias do dealer;
    const int dist_borderX = 700;
    const int dist_borderY = 85;
    int cX = dist_borderX;
    int cY = dist_borderY;
    for(int j = 0; j<3; j++){
        cartasDealer[j].h = height_card;
        cartasDealer[j].w = width_card;
        cartasDealer[j].x = cX;
        cartasDealer[j].y = cY;
        cX += width_card + 20;
    }
    //Distancia botoes
    const int dis_botX = 500;
    const int dis_botY = 300;
    int bX = dis_botX + 100;
    int bY = dis_botY + 100;
    botaoCompra.h = 120;
    botaoCompra.w = 200;
    botaoCompra.x = bX;
    botaoCompra.y = bY;

    botaoManter.h = 110;
    botaoManter.w = 200;
    botaoManter.x = bX + 250;
    botaoManter.y = bY;

    //Tela de vc perdeu

    you_lose.h = 900;
    you_lose.w = 900;
    you_lose.x = 1000;
    you_lose.y = 100;

    play_again.h = 100;
    play_again.w = 150;
    play_again.x = 1100;
    play_again.y = 400;

    you_win.h = 900;
    you_win.w = 900;
    you_win.x = 1000;
    you_win.y = 100;

    empate_rect.h = 900;
    empate_rect.w = 900;
    empate_rect.x = 1000;
    empate_rect.y = 100;

    carta_animacao.h = height_card;
    carta_animacao.w = width_card;
    
    carta_animacao_player.w = width_card;
    carta_animacao_player.h = height_card;
    
    /* //Carregar texto saldo
    saldoPlayerRect.h = 300;
    saldoPlayerRect.w = 100;
    saldoPlayerRect.x = X1 + 200;
    saldoPlayerRect.y = Y1; */
    load_texture_empate();
    load_texture_lose();
    load_texture_win();
    load_texture_bot();
    load_texture_deck();
    load_texture_cartas_player();
    criar_deck();
    //Coordenada do deck de compra;
    deck_compra.coor_pilha.x = deckCompra.x;
    deck_compra.coor_pilha.y = deckCompra.y;
    deck_compra.coor_pilha.w = deckCompra.w;
    deck_compra.coor_pilha.h = deckCompra.h;
    
    new_game();
}

int main(){

    bool quit = false;

    if(!InicializarSDL()){
        return 1;
    }
    carregarGame();
    

    bool ganhou = false;
    bool perdeu = false;
    bool empate = false;
    while(!quit){
        SDL_SetRenderDrawColor(render, 8, 124, 6, 255);
        SDL_RenderClear(render);
        
        while(SDL_PollEvent(&e) != 0){
            SDL_GetMouseState(&mouseX, &mouseY);
            if(e.type == SDL_QUIT){
                quit = true;
            }
            
            if(SDL_MOUSEBUTTONDOWN == e.type){
                clicked = true;
            }
        }

        atualizarInterface();
        if(clicked){
            if(!ganhou && !perdeu && !empate && cliqueiManter()){
                dealer.player_cards[2].numero = 0;
                dealer_action();
                dealer.player_cards[1].turn = false;

                if(somaCartas(&player)>somaCartas(&dealer) && somaCartas(&player)<=21){
                    ganhou = true;
                }
                else if(somaCartas(&player)<somaCartas(&dealer) && somaCartas(&dealer)>21){
                    ganhou = true;
                }
                else if(somaCartas(&player)>somaCartas(&dealer) && somaCartas(&player)>21 ){
                    perdeu = true;
                }
                else if(somaCartas(&player)<somaCartas(&dealer) && somaCartas(&dealer)<=21){
                    perdeu = true;
                }
                else if(somaCartas(&player)==somaCartas(&dealer)){
                    empate = true;
                }
            }

            if(clicandoPlayAgain() && (ganhou || perdeu || empate)){
                new_game();
                ganhou = perdeu = empate = false;
            }
            clicked = false;
        }

        if(animacao){
            if(animacaoDealer()){
                animacao = false;
                zerar_carta_animacao();
            }
        }

        if(animacao2 && !animacao){
            if(animacaoPlayer()){
                animacao2 = false;
                zerar_carta_animacao2();
            }
        }


        if(!animacao && !animacao2){
            if(ganhou){
                atualizar_tela_ganhou();
            }
            else if(perdeu){
                atualizar_tela_perdeu();
            }
            else if(empate){
                atualizar_tela_empate();
            }
        }



        SDL_RenderPresent(render);
        SDL_Delay(1);
    }
    SDL_Quit();
}