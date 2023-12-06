/*
 * task2.c
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
	DDRA |= 0x3F;
	
    while (1) 
    {
		for (int i=0;i<6;i++)
		{
			PORTA |= (1<<i);
			_delay_ms(500);
		}
		for (int i=5;i>=0;i--)
		{
			PORTA &= ~(1<<i);
			_delay_ms(500);
		}
		
		_delay_ms(1000);
		
    }
}

