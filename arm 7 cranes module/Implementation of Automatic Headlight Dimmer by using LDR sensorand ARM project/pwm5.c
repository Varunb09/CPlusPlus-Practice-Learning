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
	PINSEL1 = 0<<11 | 1<<10;
	IODIR0 |= 1<<7;
	PWMPR = 14;
	//PWMTCR = 1<<1;
	PWMMR0 = 1000000;
	PWMTCR = 1<<0 | 1<<3;
	PWMLER = 1<<0;
	PWMMCR = 1<<1;
	PWMPCR = 1<<13;
	
	
	while(1)
	{
		PWMMR5 = 100000;
		PWMLER = 1<<5;
		delay(1000);

		PWMMR5 = 500000;
		PWMLER = 1<<5;
		delay(1000);
	}
}
