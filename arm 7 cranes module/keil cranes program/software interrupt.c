#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i=0;i<c;i++)
	for(j=0;j<1000;j++);
}
void eint_isr(void)__irq
{
		IOSET1 = 1<<17;
		delay(1000);
		IOCLR1 = 1<<17;
		delay(1000);
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		delay(1000);
		VICSoftIntClr = 1<<17;
		delay(1000);
		VICSoftIntClr = 1<<15;
		delay(1000);
		VICVectAddr = 0;
		EXTINT = 1<<1|1<<3;
}
int main()
{
	IODIR1 = 1<<17;
	IODIR0 = 1<<25;
	VICIntEnable = 1<<17|1<<15;
	VICIntSelect = 0<<17|0<<15;
	VICDefVectAddr = (long)(eint_isr);

	while(1)
	{
		VICSoftInt = 1<<17;
		delay(10000);
		VICSoftInt = 1<<15;
		delay(10000);
	}
}
	
