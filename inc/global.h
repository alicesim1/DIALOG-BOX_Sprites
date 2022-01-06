#ifndef _GLOBAL_H
#define _GLOBAL_H
//------------------------------------------------------------------------------------------
#include "../res/basicos.h"//fuente, pinguno jug, cursor,

//-----------------------------------------------

u16 BUTTONS[12];
bool gat;//GATILLO GLOBAL!

char char_salida[8];

#define diag_ind 200 //VRAM hex:4B0
void dialogo(u16,u16,u8,u8,u8);

#endif
