#include<lpc214x.h>
//#include"lcd link.h"


void heartbeat()
{
	long result1 = 0;
	lcd();
	PINSEL1 = 0<<27|1<<26;
	AD0CR = 1<<2|4<<8|1<<16|1<<21;
	while(!(AD0GDR & 1<<31));
	result1 = ((AD0GDR>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
	display(result1);
	delay(1000);
	command(0x01);
}