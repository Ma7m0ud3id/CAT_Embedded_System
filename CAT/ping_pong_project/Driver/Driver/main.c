/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
#include "DIO.h"
EXTI_Typedef EXTI_con;
uint8_t flag;
void Get_LED(){
	Toggel_PIN(PORTC,PIN0);
	_delay_ms(200);
	//_delay_ms(2000);
}
void Get_Flag_1(){
	DIR_PIN(DDRC,PIN2,OUTPUT);
	Set_PIN(PORTC,PIN2);
	_delay_ms(2000);
	flag=1;
}
void Get_Flag_2(){
	DIR_PIN(DDRC,PIN2,OUTPUT);
	Toggel_PIN(PORTC,PIN2);
	_delay_ms(2000);
	flag=0	;
}
int main(void)
{
	Lcd_init();
	Send_string("HELLO Mahmoud");
	_delay_ms(500);
	LCD_clear_screen();
	unsigned char CHAR[] = {0x00,0x04,0x0E,0x0F,0x0F,0x0E,0x04,0x00};
	
	LCD_WRITE_S_CHAR(CHAR,5);
	LCD_clear_screen();
	
	EXTI_con.EXTI_Name=INT0;
	EXTI_con.EXTI_Mode=rising;
	EXTI_con.EXTI_Function=Get_Flag_1;
	DIR_PIN(DDRD,PIN2,INPUT);
	DIR_PIN(DDRD,PIN3,INPUT);
	EXTI_INIT(&EXTI_con);
	Send_string("INT 1 GOOD");
	LCD_clear_screen();
	
	EXTI_con.EXTI_Name=INT1;
	EXTI_con.EXTI_Mode=rising;
	EXTI_con.EXTI_Function=Get_Flag_2;
	DIR_PIN(DDRD,PIN2,INPUT);
	DIR_PIN(DDRD,PIN3,INPUT);
	EXTI_INIT(&EXTI_con);
	
	Send_string("INT 2 GOOD");
	LCD_clear_screen();
	
	int8_t i=0;
	flag=0;
	LCD_clear_screen();
	while(1){

		for (; i < 16; ++i)
		{
			if(flag==1){
				
				Send_string("Switch to two");
				LCD_clear_screen();
				break;
			}else{
				//diplay line 1 , position i
				LCD_WRITE_S_CHAR(CHAR,i);
				_delay_ms(200);
				LCD_clear_screen();
				
				
			}
		}
		if(i==16){
			
			Send_string("two loooooos");
			LCD_clear_screen();
			break;
		}
        
		for (; i >= 0; --i)
		{
			if(flag==0){
				
				Send_string("Switch to one");
				LCD_clear_screen();
				break;
			}else{
				//diplay line 1 , position i
				LCD_WRITE_S_CHAR(CHAR,i);
				_delay_ms(200);
				LCD_clear_screen();
				/*LCD_WRITE_CHAR(flag);
				LCD_clear_screen();*/
			}
		}
		if(i<0){
			
			Send_string("one loooooos");
			LCD_clear_screen();
			break;
		}


	}
	/* Replace with your application code */
	_delay_ms(2000);
	LCD_clear_screen();
   
}

