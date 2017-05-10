/*
 * Question_Mark_Advanced.c
 *
 * Created: 18-Mar-16 5:26:01 PM
 *  Author: LENOVO
 */ 

#include "Display.h"
#include "BTN.h"
#include "lcd_4bit.h"
#include "Keypad.h"
#include <util/delay.h>
#include "Quetions.h"
#include <stdlib.h>

#define WAIT while(Btn_Read(BTN_NXT)==BTN_INACTIVE)

int main(void)
{
	BTN_Init();
	lcd_init();
	Keypad_Init();
	DIO_InitPortDirection(PD,0xFF,0xFE);
	
	u8 QuesIndex = 0 ;
	int usrAns = 0;
	int sramNum = 0 ;
	
    while(1)
    {
		srand(sramNum++) ;
		QuesIndex = (rand()%QUESTIONS_NUMBER)+1 ;
		DIO_WritePort(PD , 0x00 , 0xFE) ;
		lcd_clrScreen();
		WAIT
			Display_welcome("Pixels");    
			
		lcd_clrScreen();
		lcd_dispString(QuestionList[QuesIndex].ques);
		_delay_ms(1000) ;
		WAIT ;
		lcd_clrScreen();
		lcd_dispString("Your Answer :") ;
		usrAns = Display_getAns();
		if(usrAns == QuestionList[QuesIndex].ans)
		{
			lcd_clrScreen();
			lcd_dispString("correct!");
			DIO_WritePort(PD ,0xFF ,0x08) ;  //relay
			//pin 3
			_delay_ms(1000) ;
		}
		else
		{
			lcd_clrScreen();
			lcd_dispString("Wrong !") ;
			DIO_WritePort(PD,0xFF , 0x10) ;    //buzzer
			DIO_WritePort(PD, 0xFF , 0x20) ;
			//pins 4 & 5
			_delay_ms(1000) ;
		}
		WAIT ;
		QuesIndex = (QuesIndex+1)%QUESTIONS_NUMBER;
    }
}