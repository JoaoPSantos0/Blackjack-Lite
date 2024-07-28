#ifndef _CARTAS_H_
#define _CARTAS_H_

#include "Interface.h"
#define NAIPE_CARTA 4
#define TIPOS_CARTAS 13
#define TOTAL_CARTAS 52

const int height_card  = 140;
const int width_card = 105;

typedef struct card{
    SDL_Rect rect;
    int naipe;
    int valor;
    int numero;
    bool turn;
}Card;



enum naipe{
    PAUS = 0, ESPADA = 1, COPAS = 2, OURO = 3
};

SDL_Texture * texture_cards[NAIPE_CARTA][TIPOS_CARTAS+1]; 
SDL_Texture * texture_player_cards[2];
SDL_Texture * texture_baralho;
SDL_Texture * texture_background;
SDL_Texture * botao_Comprar;
SDL_Texture * botao_Manter;
SDL_Texture * textureFont;
SDL_Texture * SaldoPlayer;
SDL_Texture * SomaCartasPlayer;
SDL_Texture * carta_Comprada;
SDL_Texture * youLose;
SDL_Texture * youWin;
SDL_Texture * playAgain;

char caminho_imagens[NAIPE_CARTA][TIPOS_CARTAS + 1][50] = {

{"","imagens/Cards/ace_of_clubs.png","imagens/Cards/2_of_clubs.png","imagens/Cards/3_of_clubs.png","imagens/Cards/4_of_clubs.png","imagens/Cards/5_of_clubs.png","imagens/Cards/6_of_clubs.png","imagens/Cards/7_of_clubs.png","imagens/Cards/8_of_clubs.png","imagens/Cards/9_of_clubs.png","imagens/Cards/10_of_clubs.png","imagens/Cards/jack_of_clubs2.png","imagens/Cards/queen_of_clubs2.png","imagens/Cards/king_of_clubs2.png"},
{"","imagens/Cards/ace_of_hearts.png","imagens/Cards/2_of_hearts.png","imagens/Cards/3_of_hearts.png","imagens/Cards/4_of_hearts.png","imagens/Cards/5_of_hearts.png","imagens/Cards/6_of_hearts.png","imagens/Cards/7_of_hearts.png","imagens/Cards/8_of_hearts.png","imagens/Cards/9_of_hearts.png","imagens/Cards/10_of_hearts.png","imagens/Cards/jack_of_hearts2.png","imagens/Cards/queen_of_hearts2.png","imagens/Cards/king_of_hearts2.png"},
{"","imagens/Cards/ace_of_spades.png","imagens/Cards/2_of_spades.png","imagens/Cards/3_of_spades.png","imagens/Cards/4_of_spades.png","imagens/Cards/5_of_spades.png","imagens/Cards/6_of_spades.png","imagens/Cards/7_of_spades.png","imagens/Cards/8_of_spades.png","imagens/Cards/9_of_spades.png","imagens/Cards/10_of_spades.png","imagens/Cards/jack_of_spades2.png","imagens/Cards/queen_of_spades2.png","imagens/Cards/king_of_spades2.png"},
{"","imagens/Cards/ace_of_diamonds.png","imagens/Cards/2_of_diamonds.png","imagens/Cards/3_of_diamonds.png","imagens/Cards/4_of_diamonds.png","imagens/Cards/5_of_diamonds.png","imagens/Cards/6_of_diamonds.png","imagens/Cards/7_of_diamonds.png","imagens/Cards/8_of_diamonds.png","imagens/Cards/9_of_diamonds.png","imagens/Cards/10_of_diamonds.png","imagens/Cards/jack_of_diamonds2.png","imagens/Cards/queen_of_diamonds2.png","imagens/Cards/king_of_diamonds2.png"}
};

Card deck[TOTAL_CARTAS];

SDL_Rect deckCompra;
SDL_Rect cartasDealer[2];
SDL_Rect cartasPlayer[2];
SDL_Rect botaoCompra;
SDL_Rect botaoManter;
SDL_Rect rectFont;
SDL_Rect saldoPlayerRect;
SDL_Rect somaCartasRect;
SDL_Rect cartaComprada;
SDL_Rect you_lose;
SDL_Rect you_win;
SDL_Rect play_again;

void criar_deck();
void embaralhar(Card arr[]);
void load_texture_lose();
void load_texture_win();
void load_texture_naipes();
void load_texture_deck();
void load_texture_cartas();
void atualizarInterface();
void load_texture_bot();
void atualizarBotoes();
void atualizar_tela_perdeu();
void atualizar_tela_ganhou();
#endif//_CARTAS_H_