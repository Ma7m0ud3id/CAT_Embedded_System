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
#include "Timer.h"
#define F_CPU  16000000U
Timer_Configration timer_con;
int main(void)
{
	
	Lcd_init();
	LCD_clear_screen();
	Send_string("HELLO Mahmoud");
	_delay_ms(1000);
	LCD_clear_screen();
	timer_con.timer_name=TIMER0;
	timer_con.Clock_Select=Timer_0_prescaling_1024;
	timer_con.Compare_Output_Mode=Timer_0_Clear_OC0;
	timer_con.Asynchronous_Status=Timer_0_NON;
	timer_con.Intial_Timer=0;
	timer_con.Wave_Form=Timer_0_Fast_PWM;
	timer_con.Timer_Call_Back_Compare=0;
	timer_con.Timer_Call_Back_overflow=0;
	Timer_Init(&timer_con);
	Timer_Set_Compare(TIMER0,200);
	Timer_0_Mask_Compere_overflow();
	DIR_PIN(DDRB,PIN3,OUTPUT);
	//****************************************
	Send_string("Timer Init");
	_delay_ms(1000);
	LCD_clear_screen();
	//****************************************
	Send_string("HELLO Mahmoud");
	_delay_ms(1000);
	LCD_clear_screen();
	//***************************************
	/*Init_LM35(&lm35_con);
	//ADC_INIT(AVCC,Division64);
	
	Send_string("ADC INIT");
	_delay_ms(500);
	LCD_clear_screen();*/
	
	while(1){
		
		//gotoXY(0,0);
		/*Send_string("ADC : ");
		data=Get_Analog_Data(&lm35_con);
		//data=ADC_READ(Ch3);
		LCD_WRITE_NUMBER(data);
		gotoXY(2,0);
		Send_string("TMP : ");
		volt=Get_Tem_Data(&lm35_con);
		//volt=(uint32_t)data*5000/1024;
		LCD_WRITE_NUMBER(volt);
		_delay_ms(1500);
		LCD_clear_screen();*/

	}
   
}
/*
//main delay



/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 

#include "LCD.h"
#include "Keypad.h"
#include "EXTI.h"
#include "DIO.h"
#include "ADC.h"
#include "LM35.h"
#include "Timer.h"
#define F_CPU  16000000U
Timer_Configration timer_con;
void P_F_Delay_Compare(void){
	NON_Global_Interrupt();
	Timer_0_NON_Mask_Compere_overflow();
	Reset_PIN(PORTB,PIN1);
}
int main(void)
{
	
	Lcd_init();
	LCD_clear_screen();
	Send_string("HELLO Mahmoud");
	_delay_ms(1000);
	LCD_clear_screen();
	timer_con.timer_name=TIMER0;
	timer_con.Clock_Select=Timer_0_prescaling_1024;
	timer_con.Compare_Output_Mode=Timer_0_Normal_OC0_disconnected;
	timer_con.Asynchronous_Status=Timer_0_NON;
	timer_con.Intial_Timer=0;
	timer_con.Wave_Form=Timer_0_Normal;
	timer_con.Timer_Call_Back_Compare=P_F_Delay_Compare;
	timer_con.Timer_Call_Back_overflow=P_F_Delay_overflow;
	Timer_Init(&timer_con);
	Timer_0_NON_Mask_Compere_overflow();
	DIR_PIN(DDRB,PIN3,OUTPUT);
	DIR_PIN(DDRB,PIN1,OUTPUT);
	DIR_PIN(DDRB,PIN2,OUTPUT);
	//****************************************
	Send_string("Timer Init");
	_delay_ms(1000);
	LCD_clear_screen();
	//****************************************
	Send_string("HELLO Mahmoud");
	_delay_ms(1000);
	LCD_clear_screen();
	//***************************************
	
	Set_PIN(PORTB,PIN1);
	Timer_Delay(TIMER0,1);
	
	Send_string("DELAY FINITION");
	_delay_ms(1000);
	LCD_clear_screen();
	
	while(1){
		
		Send_string("Fast PWM");
		_delay_ms(1000);
		LCD_clear_screen();
		
		
		
		
		

	}
   
}
//**********************************************************************************

*/