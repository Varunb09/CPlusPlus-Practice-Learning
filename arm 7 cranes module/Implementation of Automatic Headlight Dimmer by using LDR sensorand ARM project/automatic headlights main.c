#include<lpc214x.h>
#include"lcd link.h"
//#include<gsm.h>


int main()
{
	unsigned int done = 1;					   
	int result = 0;
	PINSEL1 |= (0<<25 | 1<<24) ;
	PINSEL0 |= (1<<15 | 0<<14);
	//AD0CR |= (1 << 1| 3 << 8| 1 << 16 | 1 << 21);
	IODIR0 |= 1<<7;
	PWMPR = 14;
	//PWMTCR = 1<<1;
	PWMMR0 = 10000;
	PWMTCR = 1<<0 | 1<<3;
	PWMLER = 1<<0;
	PWMMCR = 1<<1;
	PWMPCR = 1<<10;


	lcd();
	while(1)
	{
		AD0CR = (1 << 1| 3 << 8| 1 << 16 | 1 << 21);
		while(!(AD0DR1 & (done << 31)));
		result = ((AD0DR1 >> 6) & 0x3ff);
		command(0x80);
		command(0x01);
		lcd_string("LDR:");
		display(result);
		delay(300);
		command(0x01);
		if(result >= 800)
		{
			lcd_string("low lights");
			PWMMR2 = 10000;
			PWMLER = 1<<2;
			delay(1000);
		}
		else if(result >= 200 && result < 800)
		{
			lcd_string("medium lights");
			PWMMR2 = 5000;
			PWMLER = 1<<2;
			delay(1000);
		}
		else
		{
			lcd_string("high lights");
			PWMMR2 = 1000;
			PWMLER = 1<<2;
			delay(1000);
			command(0x01);
		}

	}
}
