/*
 * LCD_01.c
 *
 * Created: 8/24/2020 11:34:52 PM
 * Author : Mina
 */ 

//#include <avr/io.h>
#include "LCD.h"
#include "KeyPad.h"
#include "Calculator.h"
int main(void)
{
uint8 button_value;
LCD_Init();
KeyPad_Init();
sint32 operand1=0;
sint32 operand2=0;
uint8 operation='+';
uint8 firsttime=0;

while (1)
{
	button_value=KeyPad_GetValue();
	if(button_value!='@')
	{
		
		if(button_value=='c')
		{
			LCD_Clear();
			operand1=0;
			operand2=0;
		}
		else if(button_value=='=')
		{
			
			switch (operation)
			{
				
				case '+':
				operand2= operand2+operand1;
				operand1=0;
				break;
				case '-':
				operand2=operand2-operand1;
				operand1=0;
				break;
				case '*':
				if (firsttime==0)
				operand2=1;
				operand2=operand2*operand1;
				operand1=0;
				break;
				case '/':
				if (firsttime==0)
				operand2=1;
				operand2=operand2/operand1;
				operand1=0;
				break;
				default:
				break;
				
			}
			Displaynumber(operand2);
			
		}
		else if (button_value=='+'||button_value=='-'||button_value=='*'||button_value=='/')
		{
			LCD_WriteData(button_value);
			switch (operation)
			{
				
				case '+':
				operand2= operand2+operand1;
				operand1=0;
				break;
				case '-':
				operand2=operand2-operand1;
				operand1=0;
				break;
				case '*':
				if (firsttime==0)
				operand2=1;
				operand2=operand2*operand1;
				operand1=0;
				break;
				case '/':
				if (firsttime==0)
				operand2=1;
				operand2=operand2/operand1;
				operand1=0;
				break;
				default:
				break;
				
			}
			firsttime=1;
			operation=button_value;
			
			operand1=0;
			
		}
		else
		{
			LCD_WriteData(button_value);
			operand1=(operand1*10)+(sint32)(button_value-0x30);
			
		}
		
		
	}
}
}