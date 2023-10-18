#include<lpc214x.h>
#include"lcd link.h"

void display(long c)
{
	if(c)
	{
		command(0x80);
	 	data('P');
		data('O');
		data('T');
		data(':');
		command(0x84);
		display(c/10);						
	
		data((c%10)+0x30); 
	}	
}
void adc_isr(void)__irq
{	
	    long result = 0;
		result = ((AD0DR2>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		display(result);
		delay(1000);
		command(0x01);
		VICVectAddr = 0;
}

int main()
{

	lcd();
	PINSEL1 = 0<<27|1<<26;
	VICIntEnable = 1<<18;
	VICIntSelect = 0<<18;
	VICVectAddr0 = (long)adc_isr;
	VICVectCntl0 = 1<<5|18;
	AD0CR = 1<<2|4<<8|1<<16|1<<21;
	AD0INTEN = 0<<8|1<<2;
	while(1);
}