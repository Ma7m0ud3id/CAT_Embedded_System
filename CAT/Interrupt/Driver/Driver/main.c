/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
EXTI_Typedef EXTI_con;

void Get_LED(){
	Toggel_PIN(PORTA,PIN0);
	_delay_ms(200);
	//_delay_ms(2000);
}
int main(void)
{
	
	
	
	EXTI_con.EXTI_Name=INT0;
	EXTI_con.EXTI_Mode=falling;
	EXTI_con.EXTI_Function=Get_LED;
	DIR_PIN(DDRA,PIN0,OUTPUT);
	DIR_PIN(DDRD,PIN2,INPUT);
	DIR_PIN(DDRD,PIN3,INPUT);
	EXTI_INIT(&EXTI_con);
	Toggel_PIN(PORTA,PIN0);
	_delay_ms(1000);
	Toggel_PIN(PORTA,PIN0);
	
	
	while(1){
		
		
	}
	/* Replace with your application code */
   
}

