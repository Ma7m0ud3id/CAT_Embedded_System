/*
 * SWITCH.h
 *
 * Created: 12/5/2023 10:42:13 PM
 *  Author: mahmo
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "DIO.h"

void SWITCH_INIT (uint8_t *DDRx,uint8_t PINx);
uint8_t SWITCH_READ (uint8_t *PINx,uint8_t pinx);




#endif /* SWITCH_H_ */