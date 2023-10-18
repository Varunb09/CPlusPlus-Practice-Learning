#include<lpc214x.h>
#include "keypad link lcd.h"
void rtc_isr(void)__irq;
void rtc_isr(void)__irq
{
		
		command(0x80);
		command(0x0c);
		data(HOUR/10 + '0');
		data(HOUR%10 + '0');
		data(':');
		data(MIN/10 + '0');
		data(MIN%10 + '0');
		data(':');
		data(SEC/10 + '0');
		data(SEC%10 + '0');
		ILR = 1<<0;
		VICVectAddr = 0;	
}

int main()
{
	PINSEL1 = 1<<29|0<<28;
	lcd();
	CCR = 1<<0|1<<4;
	CIIR = 1<<0;
	SEC = 0;
	MIN = 0;
	HOUR = 0;
	VICIntEnable = 1<<13;
	VICIntSelect = 0<<13;
	VICVectAddr0 = (long)rtc_isr;
	VICVectCntl0 = 1<<5|13;
	while(1);

}