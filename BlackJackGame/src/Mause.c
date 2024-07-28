#include "All.h"

bool taClicando(SDL_Rect * tam){
    if(!clicked) return false;
    if(mouseX < tam->x) return false;
    if(mouseX > tam->x + tam->w) return false;
    if(mouseY < tam->y) return false;
    if(mouseY > tam->y + tam->h) return false;
    return true;
}

void cliqueiManter(){
    if(taClicando(&botaoManter)){
        dealer.player_cards[1].turn = false;
    }
    
}

bool clicandoPlayAgain(){
    if(taClicando(&play_again)){
        return true;
    }
    return false;
}
void cliqueiComprar(){
    if(taClicando(&botaoCompra)){

    }
}

