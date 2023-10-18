#include<lpc214x.h>
#include"lcd link.h"

void display(long c)
{
	if(c)
	{
		display(c/10);
		data((c%10)+0x30); 
	}	
}

int main()
{
	long result = 0;
	lcd();
	PINSEL1 = 0<<29|1<<28;
	while(1)
	{
		AD0CR = 1<<3|4<<8|1<<16|1<<21;
		while(!(AD0GDR & 1<<31));
		result = ((AD0GDR>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		display(result);
		

		delay(1000);
		command(0x01);
	}
}