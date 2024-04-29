/*
 * Driver.c
 *
 * Created: 12/14/2023 4:15:58 PM
 * Author : mahmo
 */ 

/*#include "LCD.h"
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
	timer_con.Compare_Output_Mode=Timer_0_Set_OC0;
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
	
	
	while(1){
		
		

	}
   
}*/

//main delay



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
#include "UART.h"
#define F_CPU  8000000U

USART_Pinconfige_t UART_Con;
uint8_t ch []="Mahmoud Eid ";
void UART_IRQ_CallBack(void){
	
	ch[0]=(uint8_t) MCAL_UART_ReceiveData(UART_DISABLE);
	MCAL_UART_SendData(&ch[0],UART_ENABLE);
	LCD_WRITE_CHAR(ch[0]);
}

int main(void)
{
	Lcd_init();
	UART_Con.DATA_SIZE=USART_8_BIT;
	UART_Con.Parity=USART_NON_PARITY;
	UART_Con.Select_Interrupt=RX_Complete;
	UART_Con.STOP_MODE=USART_1_STOP_BIT;
	UART_Con.UART_Baud_Rate=USART_BaudRate_9600_RESET_U2X;
	UART_Con.UART_MODE=UART_TX_RX;
	UART_Con.UART_TYPE=Asynchronous;
	UART_Con.IRQ_FUNCTION_RX_Complete=UART_IRQ_CallBack;
	UART_Con.IRQ_FUNCTION_TX_Complete=UART_IRQ_CallBack;
	UART_Con.IRQ_FUNCTION_Register_Empty=UART_IRQ_CallBack;
	MCAL_UART_Init(&UART_Con);
	
	
	for (int i=0;i<strlen(ch);i++){
		MCAL_UART_SendData(&ch[i],UART_ENABLE);
	}
	Send_string(ch);
	
	
	/*ch[0]=(uint8_t) MCAL_UART_ReceiveData(UART_DISABLE);
	MCAL_UART_SendData(&ch[0],UART_ENABLE);
	LCD_WRITE_CHAR(ch[0]);*/
	
	
	
	while(1){
		
		//_delay_ms(100);	

	}
   
}
//**********************************************************************************

