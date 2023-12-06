/*
 * task4.c
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


uint8_t segCthd[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
int8_t counter=0;	

int main(void)
{
    /* Replace with your application code */
	DDRA |= 0xFF;
	DDRB &= 0x03;
	
    while (1) 
    {
		//PORTA &=~(3<<0);
		PORTA = segCthd[counter];
		
		
		if(counter<0){
			counter=0;
		}else if(counter>9){
			counter=9;
		}else{
			
			if((PINB>>0)&1){
				counter++;
				while((PINB>>0)&1);
				
				}else if((PINB>>1)&1){
				counter--;
				while((PINB>>1)&1);
			}
			
		}
		
		
		
    }
}

