/*
 * LED.h
 *
 * Created: 12/5/2023 10:42:00 PM
 *  Author: mahmo
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"


void LED_INIT (uint8_t *DDRx,uint8_t PINx);
void LED_SET (uint8_t *PORTx,uint8_t PINx);
void LED_RESET (uint8_t *PORTx,uint8_t PINx);
void LED_Toggel (uint8_t *PORTx,uint8_t PINx);



#endif /* LED_H_ */