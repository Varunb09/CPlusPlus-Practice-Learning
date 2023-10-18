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
	long result = 0, channel = 0;
	lcd();
	PINSEL1 = 0<<29|1<<28;
	while(1)
	{
		AD0CR = 1<<3|4<<8|1<<16|1<<21;
		while(!(AD0GDR & 1<<31));
		result = ((AD0GDR>>6) & 0x3ff);  //global data register
		command(0x80);
		display(result);
		channel = ((AD0GDR>>24) & 0x07);
		command(0xc0);
		display(channel);
		delay(1000);
	//	command(0x01);
	}
}