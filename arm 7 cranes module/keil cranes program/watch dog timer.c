#include<lpc214x.h>

void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{
	IODIR0 = 1<<25;
	IODIR1 = 1<<17;
	IOCLR0 = 1<<25;
	IOSET1 = 1<<17;
	//delay(1000);
	IOCLR1 = 1<<17;

	delay(100000); 
	WDMOD = 1<<0|1<<1;
	WDTC = 0xffffffff;
	WDFEED=0xAA;
	WDFEED = 0x55;
	while(1)
	{
		IOSET0 = 1<<25;
	}
}
		