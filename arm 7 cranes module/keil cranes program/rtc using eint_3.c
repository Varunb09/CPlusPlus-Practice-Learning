#include<lpc214x.h>
#include "lcd link.h"
void eint3_isr(void)__irq;
void rtc_isr(void)__irq;

void eint3_isr(void)__irq
{
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;
//	delay(1000);
	VICVectAddr = 0;
	EXTINT = 1<<3;
}

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
	lcd();
	PINSEL1 = 1<<29|0<<28;
	CCR = 1<<0|1<<4;
	CIIR = 1<<0;
	SEC = 0;
	MIN = 0;
	HOUR = 0;
	VICIntEnable = 1<<13|1<<17;
	VICIntSelect = 0<<13|0<<17;
	VICVectAddr1 = (long)rtc_isr;
	VICVectCntl1 = 1<<5|13;

	VICVectAddr0 = (long)eint3_isr;
	VICVectCntl0 = 1<<5|17;
	EXTMODE = 1<<3;
	EXTPOLAR = 0<<3;
	while(1);

}
