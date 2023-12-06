/*
 * project_1.c
 *
 * Created: 12/6/2023 7:17:09 PM
 * Author : mahmo
 */ 

#include "LCD.h"
#include "Keypad.h"


int main(void)
{
	
	
	
	Lcd_init();
	Keypad_Init();
	_delay_ms(50);
	unsigned char key_pressed;
	uint8_t counter1=0;
	uint8_t counter2=0;
	long long num1,num2,product=0;
	float mul;
	unsigned char Number1[32];
	unsigned char Number2[32];
	unsigned char result[32];
	unsigned char flag=0;
	unsigned char opration;
	while(1){
		
		key_pressed = Keypad_Result();
		
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			LCD_clear_screen();
			break;
			default:
			if(key_pressed=='+'||key_pressed=='-'||key_pressed=='*'||key_pressed=='/'){
				//printf("==================================================2\n");
				LCD_WRITE_CHAR(key_pressed);
				flag=1;
				opration=key_pressed;

				}else if(key_pressed =='='){
				LCD_WRITE_CHAR(key_pressed);
				Number1[counter1]='\0';
				Number2[counter2]='\0';
				num2=atoi(Number2);
				//printf(" num2= %d\n ",num2);
				//fflush(stdin);fflush(stdout);
				num1=atoi(Number1);
				//printf("num1 =%d\n ",num1);
				if(opration=='+'){
					product=num1+num2;
					sprintf(result, "%d", product);
					}else if(opration=='-'){
					product=num1-num2;
					sprintf(result, "%d", product);
					}else if(opration=='*'){
					product=num1*num2;
					sprintf(result, "%d", product);

					}else if(opration=='/'){
                     mul=((float)num1/(float)num2);
					sprintf(result, "%f", mul);

				}
				
				//printf("sum=%d\n",product);
				//printf("==============================================================\n");
				//sprintf(result, "%d", product);
				Send_string(result);
				 counter1=0;
				 counter2=0;
				 product=0;
				 flag=0;
				//printf("The string is: %s\n", result);
				//printf("==============================================================\n");
				//break;

				}else{
				LCD_WRITE_CHAR(key_pressed);
				if(flag==0){
					Number1[counter1]=key_pressed;
					counter1++;
				}else if(flag==1){
					Number2[counter2]=key_pressed;
					// printf("=====================   %c   ======= %d\n",Number2[counter2],counter2);
					counter2++;
				}
				

			//LCD_WRITE_CHAR(key_pressed);
			break;
		             }
				}
		
	}
    /* Replace with your application code */
   
}

