/*
 * KeyPad.c
 *
 * Created: 8/29/2020 7:33:00 AM
 *  Author: Mina
 */ 

#include "KeyPad.h"
#define F_CPU 16000000
#include <util/delay.h>

#define COL_INIT	0
#define COL_FINAL	3

#define ROW_INIT	4
#define ROW_FINAL	7

const uint8 KeyPad_Values[4][4]={ {'7','8','9','/'},
	                              {'4','5','6','*'},
								  {'1','2','3','-'},
								  {'c','0','=','+'}};
									   
								   

void KeyPad_Init(void)
{
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLOUM_0, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLOUM_1, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLOUM_2, DIO_PIN_OUTPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLOUM_3, DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_0, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_1, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_2, DIO_PIN_INPUT);
	DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_3, DIO_PIN_INPUT);
	
	DIO_SetPullup(KEYPAD_PORT, KEYPAD_ROW_0);
	DIO_SetPullup(KEYPAD_PORT, KEYPAD_ROW_1);
	DIO_SetPullup(KEYPAD_PORT, KEYPAD_ROW_2);
	DIO_SetPullup(KEYPAD_PORT, KEYPAD_ROW_3);
	
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_0, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_1, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_2, DIO_PIN_HIGH);
	DIO_SetPinValue(KEYPAD_PORT, KEYPAD_COLOUM_3, DIO_PIN_HIGH);
	
	
}

uint8 KeyPad_GetValue(void)
{
	uint8 LOC_Coloum =0;
	uint8 LOC_Row =0;
	uint8 value ='@';
	uint8 Temp =0;
	
	for (LOC_Coloum=COL_INIT; LOC_Coloum<= COL_FINAL;LOC_Coloum++)
	{
		DIO_SetPinValue(KEYPAD_PORT, LOC_Coloum, DIO_PIN_LOW);
		for (LOC_Row=ROW_INIT; LOC_Row<= ROW_FINAL; LOC_Row++)
		{
			DIO_ReadPin(KEYPAD_PORT, LOC_Row, &Temp);
			
			if(!Temp)
			{
				value=KeyPad_Values[LOC_Row - ROW_INIT ][LOC_Coloum - COL_INIT];
				
				while(!Temp)
				{
			DIO_ReadPin(KEYPAD_PORT, LOC_Row, &Temp);		
				}
				_delay_ms(10);
				
			}
		}
		DIO_SetPinValue(KEYPAD_PORT, LOC_Coloum, DIO_PIN_HIGH);
	}
	return value;
}