#include<lpc214x.h>
#include"lcd link.h"
					 
void display(long c);


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
	long result1 = 0;
	long result2 = 0;
	long result3 = 0;
	long result4 = 0;
	lcd();
	PINSEL1 = 0<<25|1<<24|0<<27|1<<26|0<<27|1<<26|0<<19|1<<18;
	AD0CR = 1<<1|4<<8|1<<16|1<<21|1<<2|1<<3|1<<4;
	while(1)
	{
	
		while(!(AD0DR1 & 1<<31));
		result1 = ((AD0DR1>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0x80);
		data('B');
		display(result1);
		delay(1000);
		//command(0x01);

		//AD0CR = 1<<2|4<<8|1<<16|1<<21;
		while(!(AD0DR2 & 1<<31));
		result2 = ((AD0DR2>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0x86);
		data('P');
		display(result2);
		delay(1000);
		//command(0x01);

		//AD0CR = 1<<3|4<<8|1<<16|1<<21;
		while(!(AD0DR3 & 1<<31));
		result3 = ((AD0DR3>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0x8b);
		data('T');
		display(result3);
		delay(1000);
		//command(0x01);

		//AD0CR = 1<<4|4<<8|1<<16|1<<21;
		while(!(AD0DR4 & 1<<31));
		result4 = ((AD0DR4>>6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0xc0);
		data('L');
		display(result4);
		delay(1000);
		//command(0x01);
	}
}

