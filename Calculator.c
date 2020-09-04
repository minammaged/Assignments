/*
 * Calculator.c
 *
 * Created: 9/1/2020 10:54:42 AM
 *  Author: Mina
 */ 

#include "Calculator.h"
#include "LCD.h"
void Displaynumber(sint32 result)
{
	
	
	uint8 counter=0;
	sint32 temp=result;
	uint8 i=0;
	
	if (result<0)
	{
		LCD_WriteData('-');
	}
	
	
	for (i=0;temp>0;i++)
	{
		counter++;
		temp=temp/10;
		
	}
	
	
	uint8 arr[counter];
	
	for (i=0;i<counter;i++)
	{
		arr[i]=result%10;
		
		result=result/10;
		
	}
	LCD_GoTo(1,0);
	for (i=counter;i>0;i--)
	{
		
		LCD_WriteData(0x30+arr[i-1]);
		
	}
}