#include<lpc214x.h>

#include"lcd link.h"

int heartrate =0,x;

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

int main()
{
	int result = 0;
	unsigned int done = 1;
	lcd();
	PINSEL1 = 0<<25|1<<24;
	PINSEL0 = 1<<15|1<<14;
	AD0CR = (1 << 1| 3 << 8| 1 << 16 | 0<<17 |1 << 21);
	while(1)
	{	
			// temperature sensor data
			command(0x80);
			lcd_string("Temp: ");
			while(!(AD0DR1 & (done << 31)));
			result = ((AD0DR1 >> 6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
			display(result/3);

 			//heart rate sensor
			VICIntEnable = 1 << 16;	 
			VICIntSelect = 0 << 16;		 
			VICVectAddr1 = (long)(heartrate_isr);	   
			VICVectCntl1 = 1<<5|16;
			EXTMODE = 1 << 2;
			EXTPOLAR = 1 << 2;	  
			if(heartrate > 1)
			{
				command(0xc0);
				lcd_string("heartrate: ");
				x = (heartrate*2)+40;
				display(x);
				heartrate = 0;
				//timer_count = 0;
			}
			//command(0x01);
			
	}
}




