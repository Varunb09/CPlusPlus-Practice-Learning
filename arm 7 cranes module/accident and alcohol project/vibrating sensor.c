#include<lpc214x.h>
#include "lcd link.h"

void viberation_isr(void)__irq
{
	
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;
	data1("done");
	EXTINT = 1<<3;
	VICVectAddr = 0;
	
}
int main()
{
	
	PINSEL1 = 1<<29|0<<28;			 //p0.7 used ent2
	lcd();
	
	IODIR0 = 1<<25;
	VICIntEnable = 1 << 17;	 
	VICIntSelect = 0 << 17;		 
	VICVectAddr0 = (long)(viberation_isr);	   
	VICVectCntl0 = 1<<5|17;
	EXTMODE = 1 << 3;
	EXTPOLAR = 0 << 3;
	while(1);	  
						   
}
