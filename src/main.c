#include "genesis.h"//[[SGDK]]
/********************************************************************************
*      @Title:  PENGUIN WORLD
*      @Author: Alicia Sanchez Martos "AliceSim1"
***********************************************************************************/
#include "../inc/global.h"
//-----------------------------------------------------

//Definiciones de las funciones---------------------------------------------------
static void inputHandler(u16,u16,u16);

/////////////////////////////INICIO DE TODO//////////////////////////////////////////////////
void main(){
	
	JOY_setEventHandler(&inputHandler);
	//----------------------------------------------
	
	SPR_init();//necesario para diaologon(funciona por Sprites!)
	
	//VDP_drawText("Total:65536 bytes",20,1);
	//memfreettxt();
	
	//--------------------------------------------------
	gat=TRUE;

    while(1){//LOOP BASICO(NUNCA SE SALE!)
		
		if(!gat){
			
			if(BUTTONS[5]){ gat=TRUE;
				strcpy(dialog_txt,"!Hola Mundo¡");
				dialogo(24,156,8,1,1,1);
			}
			if(BUTTONS[6]){ gat=TRUE;
				strcpy(dialog_txt,dialogos[0]);
				dialogo(24,140,8,2,1,1);
			}
			if(BUTTONS[7]){ gat=TRUE;
				strcpy(dialog_txt,dialogos[1]);
				dialogo(0,0,4,6,1,1);
			}
			if(BUTTONS[8]){ gat=TRUE;
				strcpy(dialog_txt,dialogos[3]);
				dialogo(0,0,4,6,1,1);
			}
			
		}else if(!BUTTONS[0]) gat=FALSE;
	
		SYS_doVBlankProcess(); // Renderizamos la pantalla
    }
}


void memfreettxt(){
	/*sprintf(char_salida, "Free: %05u bytes", MEM_getFree());
	VDP_drawText(char_salida, 20, 2);
	sprintf(char_salida, "Used: %05u bytes", 65536 - MEM_getFree());
	VDP_drawText(char_salida, 20, 3);*/
}

/**
 * Manejador de entrada
 * joy-> Indica el mando que ha activado la entrada
 * state -> Indica el estado del mando (boton activo)
 * changed -> indica si ha cambiado (pulsado o solatado)
 * */
void inputHandler(u16 joy, u16 state, u16 changed){
   
    BUTTONS[0]=changed;

	BUTTONS[1]=changed & BUTTON_UP;
	BUTTONS[2]=changed & BUTTON_DOWN;
	BUTTONS[3]=changed & BUTTON_LEFT;
	BUTTONS[4]=changed & BUTTON_RIGHT;
	
	BUTTONS[5]=changed & BUTTON_A;
	BUTTONS[6]=changed & BUTTON_B;
	BUTTONS[7]=changed & BUTTON_C;

	BUTTONS[8]=changed & BUTTON_START;
	
}
