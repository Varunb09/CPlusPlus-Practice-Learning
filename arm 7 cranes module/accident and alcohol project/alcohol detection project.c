#include<lpc214x.h>
#include"lcd link.h"


int main()
{
	int result = 0;
	unsigned int done = 1;
	lcd();
	PINSEL1 = 0<<25|1<<24;		//p0.28
	while(1)
	{
		command(0x80);
		lcd_string("Alcohol val:");

		AD0CR = (1 << 1| 3 << 8| 1 << 16 | 0<<17 |1 << 21);
		while(!(AD0DR1 & (done << 31)));
		result = ((AD0DR1 >> 6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		command(0xc0);
		display(result);
		delay(1000);
	}
}

