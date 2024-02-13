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
#include "ADC.h"
#include "LM35.h"
LM35_Configration lm35_con;
int main(void)
{
	uint16_t data;
	uint32_t volt;
	Lcd_init();
	lm35_con.type=AVCC;
	lm35_con.prescaler=Division64;
	lm35_con.ch=Ch3;
	Send_string("HELLO Mahmoud");
	_delay_ms(500);
	LCD_clear_screen();
	Init_LM35(&lm35_con);
	//ADC_INIT(AVCC,Division64);
	
	Send_string("ADC INIT");
	_delay_ms(500);
	LCD_clear_screen();
	
	while(1){
		//gotoXY(0,0);
		Send_string("ADC : ");
		data=Get_Analog_Data(&lm35_con);
		//data=ADC_READ(Ch3);
		LCD_WRITE_NUMBER(data);
		gotoXY(2,0);
		Send_string("TMP : ");
		volt=Get_Tem_Data(&lm35_con);
		//volt=(uint32_t)data*5000/1024;
		LCD_WRITE_NUMBER(volt);
		_delay_ms(1500);
		LCD_clear_screen();

	}
   
}