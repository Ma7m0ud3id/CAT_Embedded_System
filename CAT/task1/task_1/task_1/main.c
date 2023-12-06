/*
 * task1.c
 *
 * Created: 12/5/2023 8:39:44 PM
 * Author : mahmo
 */ 

#include <stdint.h>
#include <util/delay.h>

#define DDRA     *((volatile uint8_t *)0x3A)
#define PORTA    *((volatile uint8_t *)0x3B)


int main(void)
{
    /* Replace with your application code */
	DDRA |= (1<<0);
	
    while (1) 
    {
		PORTA |= (1<<0);
		_delay_ms(1000);
		PORTA &= ~(1<<0);
		_delay_ms(1000);
		
    }
}

