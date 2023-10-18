#include<lpc214x.h>
#include "lcd link.h"

int heartrate =0,timer_count,x;

void heartrate_isr(void)__irq
{
	T1TCR = 1<<0;
	T1MR0 = 30000000;
	T1PR = 14;
	T1MCR = 0x3 << 0;
	if(!(T1IR & 1<<0))
	{
		EXTINT = 1<<2;
		heartrate++;
		T1IR = 1<<0;
	}
	//display(heartrate);
	VICVectAddr = 0;
	
}
/*void timer_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
		timer_count++;
		
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		T1IR = 1<<0;
}*/
int heartrate_isr()
{
	
	PINSEL0 |= 1<<15|1<<14;			 //p0.7 used ent2
	lcd();
	
	
	VICIntEnable = 1 << 16;	 
	VICIntSelect = 0 << 16;		 
	VICVectAddr1 = (long)(heartrate_isr);	   
	VICVectCntl1 = 1<<5|16;
	EXTMODE = 1 << 2;
	EXTPOLAR = 1 << 2;	  
	while(1)
	{
	if(heartrate > 1)
	{
		command(0x01);
		lcd_string("heartrate: ");
		x = (heartrate*2)+40;
		display(x);
		heartrate = 0;
		//timer_count = 0;
	}
	delay(500);
	}
						   
}

