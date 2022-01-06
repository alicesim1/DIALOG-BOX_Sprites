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
	
	PAL_setPalette(PAL2,dig_marco1.palette->data,CPU);
	
	
	
	SPR_init();
	
	Sprite* dig_temp[3];
	dig_temp[0]=SPR_addSpriteEx(&dig_marco1,0,0,diag_ind,0,SPR_FLAG_AUTO_SPRITE_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD);
	dig_temp[1]=SPR_addSpriteEx(&dig_marco2,0,0,diag_ind+1,0,SPR_FLAG_AUTO_SPRITE_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD);
	dig_temp[2]=SPR_addSpriteEx(&dig_marco3,0,0,diag_ind+1+4,0,SPR_FLAG_AUTO_SPRITE_ALLOC | SPR_FLAG_AUTO_TILE_UPLOAD);
	
	SPR_update();//VOLCAMOS ACTUALIZACION Y PINTADO DE SPRITES
	for(u8 i=0;i<3;i++)	SPR_releaseSprite(dig_temp[i]);//LIBERAMOS LOS SLTOS DE SPRITES
	SPR_update();//BORRAMOS SPRITES(BORRA SLOTS, NO BORRA VRAM, NI DATOS SPRITES)
	
	VDP_drawText("Total:65536 bytes",20,1);

	//--------------------------------------------------
	gat=TRUE;
    while(1){//LOOP BASICO(NUNCA SE SALE!)
		
		if(!gat){
			if(BUTTONS[6]){ gat=TRUE;
				dialogo(0,0,4,6,0);
			}
			if(BUTTONS[5]){ gat=TRUE;
				dialogo(0,0,4,6,1);
			}
			if(BUTTONS[7]){ gat=TRUE;
				dialogo(0,0,4,6,2);
			}
			if(BUTTONS[8]){ gat=TRUE;
				dialogo(0,0,4,6,3);
			}
			
		}else if(!BUTTONS[0]) gat=FALSE;
		
		sprintf(char_salida, "Free: %05u bytes", MEM_getFree());
		VDP_drawText(char_salida, 20, 2);
		sprintf(char_salida, "Used: %05u bytes", 65536 - MEM_getFree());
		VDP_drawText(char_salida, 20, 3);
	
		SYS_doVBlankProcess(); // Renderizamos la pantalla
    }
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
	
	BUTTONS[9]=changed & BUTTON_X;
	BUTTONS[10]=changed & BUTTON_Y;
	BUTTONS[11]=changed & BUTTON_Z;
	BUTTONS[12]=changed & BUTTON_MODE;
	
}
