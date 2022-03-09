#ifndef _GLOBAL_H
#define _GLOBAL_H
//------------------------------------------------------------------------------------------
#include "../res/basicos.h"//fuente, pinguno jug, cursor,

//-----------------------------------------------

u16 BUTTONS[12];
bool gat;//GATILLO GLOBAL!
char char_salida[8];

char dialog_txt[128];

void memfreettxt();

extern const char *dialogos[];


void dialogo(u16 x,u16 y,u8 ancho, u8 alto, u16 diag_ind,u8 diag_pal);
#endif
