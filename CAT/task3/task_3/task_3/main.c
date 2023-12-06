/*
 * task2.c
 *
 * Created: 12/5/2023 8:39:44 PM
 * Author : mahmo
 */ 

#include <stdint.h>
#include <util/delay.h>
//
#define DDRA     *((volatile uint8_t *)0x3A)
#define PORTA    *((volatile uint8_t *)0x3B)
#define PINA     *((volatile uint8_t *)0x39)

//
#define DDRB     *((volatile uint8_t *)0x37)
#define PORTB    *((volatile uint8_t *)0x38)
#define PINB     *((volatile uint8_t *)0x36)

int main(void)
{
    /* Replace with your application code */
	DDRA |= 0x03;
	DDRB &= 0x07;
	
    while (1) 
    {
		PORTA &=~(3<<0);
		if((PINB>>0)&1){
			PORTA |=(1<<0);
			PORTA &=~(1<<1);
			while((PINB>>0)&1);
			
		}else if((PINB>>1)&1){
			PORTA |=(1<<1);
			PORTA &=~(1<<0);
			while((PINB>>1)&1);
			
		}else if((PINB>>2)&1){
			PORTA |=(0b11<<0);
			while((PINB>>2)&1);
		}
		
    }
}

