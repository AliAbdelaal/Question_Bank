/*
 * Display.c
 *
 * Created: 18-Mar-16 5:31:13 PM
 *  Author: LENOVO
 */ 

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "StdTypes.h"
#include "Display.h"
#include "BTN.h"
#include "lcd_4bit.h"
#include "Keypad.h"
#include <util/delay.h>


// state 0 right 1 left
static u8 state = 0 ;
static u8 Xindex = 0;
void Display_welcome(char* msg)
{
	
	u8 rotateNumber = (16-(strlen(msg))) ;
	if(state==0)
	{
		if(Xindex==(rotateNumber-1))
		{
			state = 1 ;
			Xindex ++ ;
		}
		else 
			Xindex++ ;
		lcd_clrScreen();
		lcd_gotoxy(Xindex , 0) ;
		lcd_dispString(msg) ;
		_delay_ms(250) ;
	}
	else
	{
		if(Xindex == 1)
		{
			state = 0 ;
			Xindex-- ;
		}
		else
			Xindex -- ;
	lcd_clrScreen();
	lcd_gotoxy(Xindex,0) ;
	lcd_dispString(msg) ;
	_delay_ms(250) ;		
	}
}


int Display_getAns()
{
	int intAns = 0 ;
	char usrAns[7] ;
	u8 arrIndex = 0 ;
	lcd_gotoxy(0,1) ;
	u8 lcdIndex = 0 ;
	while(1)
	{
		char inKey = Keypad_Read() ;
		if(inKey == '#')
			break ;
		else if (inKey == '*')
		{
			if(arrIndex==0) ;
			else
			{
				arrIndex-- ;
				usrAns[arrIndex] = ' ' ;
				lcdIndex-- ;
				lcd_gotoxy(lcdIndex, 1) ;
				lcd_displayChar(' ') ;
// 				lcdIndex -- ;
 				lcd_gotoxy(lcdIndex , 1) ;
				_delay_ms(250);
			}
		}
		else if (inKey=='1' || inKey =='2' || inKey =='3' || inKey =='4' || inKey =='5' || inKey =='6' || inKey =='7' || inKey =='8' || inKey =='9'|| inKey =='0')
		{
			if(arrIndex==5) ;
			else 
			{
				usrAns[arrIndex] = inKey ;
				arrIndex++ ;
				lcd_displayChar(inKey) ;
				lcdIndex++ ;
				_delay_ms(250) ;
			}
		}
	}
	usrAns[arrIndex] ='\0';
	
// 	lcd_clrScreen();
// 	lcd_dispString("string : ") ;
// 	lcd_dispString(usrAns);
	intAns = atoi(usrAns) ;
// 	lcd_gotoxy(0,1) ;
// 	lcd_dispString("int : ") ;
// 	lcd_displayInt(intAns) ;
// 	_delay_ms(2000) ;
		
	return intAns ;
}



	
// 	while(1)
// 	{
// 		if(Keypad_Press()==KEYPRESSED)
// 		{
// 			lcd_clrScreen();
// 			lcd_displayChar(Keypad_Read()) ;
// 			_delay_ms(500) ;
// 		}
// 	}
