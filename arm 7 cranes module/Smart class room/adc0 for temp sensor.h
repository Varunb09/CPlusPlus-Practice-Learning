#include<lpc214x.h>
#include"lcd link.h"

void display(int c)
{
	if(c)
	{
		display(c/10);
		data((c%10)+0x30); 
	}	
}

int main()
{
	int result = 0;
	unsigned int done = 1;
	lcd();
	//lcd_string("Temp ");
	//PINSEL1 = 0<<25|1<<24;
	while(1)
	{

		lcd_string("Temp: ");

		AD0CR = (1 << 1| 3 << 8| 1 << 16 | 0<<17 |1 << 21);
		while(!(AD0DR1 & (done << 31)));
		result = ((AD0DR1 >> 6) & 0x3ff);  //AD0.2 used in DR2 register	as channel 2
		display(result/3);
		delay(1000);
		command(0x01);
	}
}

