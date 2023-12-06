/*
 * DIO.c
 *
 * Created: 12/5/2023 10:38:30 PM
 *  Author: mahmo
 */ 

#include "DIO.h"
#include <stdint.h>



void DIR_PORT (uint8_t *DDRx,uint8_t state){
	if(OUTPUT==state){
		*DDRx|=0xff;
	}else if(INPUT==state){
		*DDRx&=~(0xff);
		
	}
	
	
}
void DIR_PIN (uint8_t *DDRx,uint8_t pin,uint8_t state){
	if(OUTPUT==state){
		*DDRx|=(1<<pin);
		}else if(INPUT==state){
		*DDRx&=~(1<<pin);
		
	}
	
	
}


uint8_t READ_PORT(uint8_t *PINx){
	return *PINx;
	
}
uint8_t READ_PIN (uint8_t *PINx,uint8_t pin){
	//uint8_t result = (*PINx &(1<<pin)>>pin);
	uint8_t result=((*PINx >> pin)&1);
	return result;
	
}

void Set_Port(uint8_t *PORTx){
	
	*PORTx=0xff;
	
}
void Set_PIN(uint8_t *PORTx,uint8_t pin){
	*PORTx|=(1<<pin);
	
}


void Toggel_PIN(uint8_t *PORTx,uint8_t pin){
	*PORTx^=(1<<pin);
}

void Reset_Port(uint8_t *PORTx){
	*PORTx&=~(0xff);
}
void Reset_PIN(uint8_t *PORTx,uint8_t pin){
	*PORTx&=~(1<<pin);
}