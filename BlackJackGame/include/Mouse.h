#ifndef __MOUSE_H__
#define __MOUSE_H__

#include "All.h"

int mouseX = 0, mouseY = 0;
bool clicked = false;
Stack mouse_list; 


void cliqueiManter();

bool taClicando(SDL_Rect* pos);

#endif//_MOUSE_H_