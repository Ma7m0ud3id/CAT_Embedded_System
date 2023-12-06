/*
 * SWITCH.c
 *
 * Created: 12/5/2023 10:41:08 PM
 *  Author: mahmo
 */ 
#include "SWITCH.h"

void SWITCH_INIT (uint8_t *DDRx,uint8_t PINx){
	DIR_PIN(DDRx,PINx,0);
}


uint8_t SWITCH_READ (uint8_t *PINx,uint8_t pinx){
	return READ_PIN(PINx,pinx);
}