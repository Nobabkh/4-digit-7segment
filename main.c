/*
 * GccApplication2.c
 *
 * Created: 4/25/2021 10:17:21 PM
 * Author : nirob
 */ 
#define POWER_DISP_ONE PORTD = 0X70;
#define POWER_DISP_TWO PORTD = 0XBF;
#define LED_OFF PORTB = 0X00
#define F_CPU 1000000UL

#include <avr/io.h>
#include <math.h>
#include <util/delay.h>

void zero()
{
	PORTB = 0XBF;
}
void one()
{
	PORTB = 0X30;
}
void two()
{
	PORTB = 0X5B;
}
void three()
{
	PORTB = 0X4F;
}
void four()
{
	PORTB = 0X66;
}
void five()
{
	PORTB = 0X6D;
}
void six()
{
	PORTB = 0X7D;
}
void seven()
{
	PORTB = 0X07;
}
void eight()
{
	PORTB = 0XFF;
}
void nine()
{
	PORTB = 0X6F;
}
void DISPLAYsingle(int i)
{
	switch(i)
	{
		case 0:
			LED_OFF;
			zero();
			break;
		
		case 1:
			LED_OFF;
			one();
			break;
			
		case 2:
			LED_OFF;
			two();
			break;
			
		case 3:
			LED_OFF;
			three();
			break;
			
		case 4:
			LED_OFF;
			four();
			break;
			
		case 5:
			LED_OFF;
			five();
			break;
			
		case 6:
			LED_OFF;
			six();
			break;
			
		case 7:
			LED_OFF;
			seven();
			break;
			
		case 8:
			LED_OFF;
			eight();
			break;
			
		case 9:
			LED_OFF;
			nine();
			break;
			
		default:
			LED_OFF;
	}
}
void numberposition(int num, int *r1, int *r0)
{
	    int pos0 = 0, pos1 = 1;
	    *r1 = num / pow(10, pos1);
	    *r1 = *r1 % 10;
		
	    *r0 = num / pow(10, pos0);
	    *r0 = *r0 % 10;
}
void DISPLAY_HOUR(int hour)
{
	int position_one, position_zero;
	numberposition(hour, &position_one, &position_zero);
	PORTD = 0XFF;
	PORTD = ~(1 << PD0);
	DISPLAYsingle(position_one);
	_delay_ms(5);
	LED_OFF;
	PORTD = 0XFF;
	PORTD = ~(1 << PD1);
	DISPLAYsingle(position_zero);
	_delay_ms(5);
}

void DISPLAY_MINUTE(int minute)
{
	int position_one, position_zero;
	numberposition(minute, &position_one, &position_zero);
	PORTD = 0XFF;
	PORTD = ~(1 << PD2);
	DISPLAYsingle(position_one);
	_delay_ms(5);
	LED_OFF;
	PORTD = 0XFF;
	PORTD = ~(1 << PD3);
	DISPLAYsingle(position_zero);
	_delay_ms(5);
}


int main(void)
{
    /* Replace with your application code */
	DDRB |= 0XFF;
	DDRD |= 0XFF;
    while (1) 
    {
		int hour = 12, minute = 40;
		DISPLAY_HOUR(hour);
		DISPLAY_MINUTE(minute);
    }
}

