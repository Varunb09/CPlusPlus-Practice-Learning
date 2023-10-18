#include<lpc214x.h>

//#include"lcd link.h"

void delay(int c)
{
	int i,j;
	for(i=0;i<c;i++)
	for(j=0;j<5000;j++);
}

int main()
{
	
	PINSEL0 = 1<<15 | 0<<14;
	IODIR0 |= 1<<7;
	PWMPR = 14;
	//PWMTCR = 1<<1;
	PWMMR0 = 10000;
	PWMTCR = 1<<0 | 1<<3;
	PWMLER = 1<<0;
	PWMMCR = 1<<1;
	PWMPCR = 1<<10;
	
	
	while(1)
	{
		 PWMMR2 = 10000;
		PWMLER = 1<<2;
		delay(1000);

		PWMMR2 = 1000;
		PWMLER = 1<<2;
		delay(1000);
	}
}
