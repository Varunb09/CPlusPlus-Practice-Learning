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

int main()
{
	long result = 0;
	lcd();
	PINSEL1 = 0<<27|1<<26;
	AD0CR = 1<<2|4<<8|0<<16|1<<21|1<<24;
	while(!(AD0DR2 & 1<<31));
	result = ((AD0DR2>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
	display(result);
	delay(100000);
}