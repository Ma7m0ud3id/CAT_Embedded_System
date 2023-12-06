/*
 * LED.c
 *
 * Created: 12/5/2023 10:40:56 PM
 *  Author: mahmo
 */ 

#include "LED.h"
void LED_INIT (uint8_t *DDRx,uint8_t PINx){
	
	DIR_PIN(DDRx,PINx,1);
	
}
void LED_SET (uint8_t *PORTx,uint8_t PINx){
	Set_PIN(PORTx,PINx);
}
void LED_RESET (uint8_t *PORTx,uint8_t PINx){
	Reset_PIN(PORTx,PINx);
	
}
void LED_Toggel (uint8_t *PORTx,uint8_t PINx){
	Toggel_PIN(PORTx,PINx);
	
}


