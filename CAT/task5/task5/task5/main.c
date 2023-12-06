/*
 * task5.c
 *
 * Created: 12/5/2023 10:38:13 PM
 * Author : mahmo
 */ 

#include "LED/LED.h"
#include "SWITCH/SWITCH.h"
#include <util/delay.h>


int main(void)
{
    LED_INIT(DDRA,PIN0);
	LED_INIT(DDRA,PIN1);
	LED_INIT(DDRA,PIN2);
	SWITCH_INIT(DDRA,PIN3);
	SWITCH_INIT(DDRA,PIN4);
	LED_Toggel(PORTA,PIN0);
	LED_Toggel(PORTA,PIN1);
	_delay_ms(2000);
	LED_Toggel(PORTA,PIN0);
	LED_Toggel(PORTA,PIN1);
    while (1) 
    {
		LED_Toggel(PORTA,PIN2);
		_delay_ms(200);
		if (SWITCH_READ(PINA,PIN3))
		{
			LED_Toggel(PORTA,PIN0);
			
		}else if(SWITCH_READ(PINA,PIN4)){
			
			LED_Toggel(PORTA,PIN1);
		}
    }
}

