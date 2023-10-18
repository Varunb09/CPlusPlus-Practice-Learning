	#include<lpc214x.h>
#include "keypad link lcd.h"

void display(int c)
	{
	int d1,d2;
	d1 = c/10;
	d2 = c%10;
	data(d1 + 0x30);
	data(d2 + 0x30);
}
int main()
{
	void lcd();
	int sec = 0,min = 0,hour = 0;
	lcd();				   //program using timer
	T1TCR = 1<<0;
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;

	while(1)
	{
		if(T1IR & 1<<0)
		{
			command(0x80);
			sec++;
			display(sec);
			delay(500);
			
			if(sec>59)
			{
					sec = 0;
					min++;
					command(0x85);
					display(min);
					if(min>59)
					{
						min=0;
						sec=0;
						command(0x8a);
						display(hour);
						hour++;
					}
			}
			T1IR = 1<<0;
		}
	}
}