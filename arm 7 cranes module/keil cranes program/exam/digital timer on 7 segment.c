#include<lpc214x.h>
#include "keypad link lcd.h"
#include "seven segment.h"
//int x,y;
/*void display(int c,int **x,int **y)
{
	int d1,d2;
	d1 = c/10;
	d2 = c%10;
	**x = d1 + 0x30;
	**y = d2 + 0x30;
	data(d1 + 0x30);
	data(d2 + 0x30);
} */
int main()
{
	int x = 0,y = 0;
	int d1,d2;
	int sec = 0,min = 0,i = 0;
	lcd();
	segment();				   //program using timer
	T1TCR = 1<<0;
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;
	digit0(i);
	digit1(i);
	digit2(i);
	digit3(i);
	while(1)
	{
		if(T1IR & 1<<0)
		{
			command(0x80);
			sec++;
			//display(sec);
			d1 = sec/10;
			d2 = sec%10;
			x = d1 + 0x30;
			y = d2 + 0x30;
			data(x);
			data(y);
			delay(1000);
			digit2(x);
			digit3(y);

			delay(500);
			
			if(sec>59)
			{
					sec = 0;
					min++;
					command(0x85);
					//display(min);
					d1 = min/10;
					d2 = min%10;
					x = d1 + 0x30;
					y = d2 + 0x30;
					data(x);
					data(y);
					delay(1000);
					digit0(x);
					digit1(y);
			}
			T1IR = 1<<0;
		}
	}
}
