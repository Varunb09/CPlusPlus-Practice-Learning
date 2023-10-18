#include<lpc214x.h>

#include "keypad link lcd.h"

int main()
{
	lcd();
//	CCR = 1<<0|1<<4|1<<1;
	CCR = 1<<0|1<<4;			 //enable rtc and source selectrtc
	CIIR = 1<<1;			   //increment counter at every minute for incrementing every second use 1<<0
	SEC = 0;				   //SEC,MIN,HOUR are predefined rtc timer variable intialized to zero
	MIN = 0;
	HOUR = 0;
	while(1)
	{
		command(0x80);
		command(0x0c);
		if(ILR & 1<<0)			   //cheak flag for interrupt location register
		{
			data(HOUR/10 + '0');		   //printind data of hour ,min,sec on led display 
			data(HOUR%10 + '0');
			data(':');
			data(MIN/10 + '0');
			data(MIN%10 + '0');
			data(':');
			data(SEC/10 + '0');
			data(SEC%10 + '0');
			ILR = 1<<0;
		}
	}

}
