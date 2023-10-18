#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void softintbuzzer()__irq
{
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;
	delay(1000);
	VICVectAddr = 0;
	VICSoftIntClr = 1<<15;
	EXTINT = 1<<1;
	 
}
void softintled()__irq
{
	IOSET1 = 1<<17;
	delay(1000);
	IOCLR1 = 1<<17;
	delay(1000);
	VICVectAddr = 0;
	EXTINT = 1<<3;
	VICSoftIntClr = 1<<17;
}
int main()
{
	IODIR1 = 1<<17;
	IODIR0 = 1<<25;
	VICIntEnable = 1<<17|1<<15;
	VICIntSelect = 0<<17|0<<15;
	VICVectAddr0 = (long)(softintbuzzer);
	VICVectAddr1 = (long)(softintled);
	VICVectCntl0 = 1<<5|15;
	VICVectCntl1 = 1<<5|17;
	while(1)
	{
		VICSoftInt = 1<<17;
		delay(10000);
		VICSoftInt = 1<<15;
		delay(10000);
  	}
}

