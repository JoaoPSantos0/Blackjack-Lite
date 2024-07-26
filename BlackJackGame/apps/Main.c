#include "All.h"
#include <stdio.h>

int main(){
    printf("Q crl\n");
    bool quit = false;

    if(!InicializarSDL()){
        return 1;
    }
    while(!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
    }
    SDL_Quit();
}