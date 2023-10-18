#include<lpc214x.h>

void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	      
		static int c = 0;
		if(c == 0)
		{
			IOSET1 = 1<<17;		  //led switching on and off program
			delay(1000);
			IOCLR1 = 1<<17;
			delay(1000);
			c = 1;
		}
		else
		{
			IOSET0 = 1<<25;		  //buzzer switching on and off program
			delay(1000);
			IOCLR0 = 1<<25;
			delay(1000);
			c = 0;			 //calling delay
		}
		VICVectAddr = 0;
		EXTINT = 1<<3;		 // making address register 0 for reseting address so that cpu resume
		EXTINT = 1<<1;			 
}
int main()
{
	PINSEL0 = 1<<29|0<<28;
	PINSEL1 = 1<<29|0<<28;			   //interrupt program for led
	IODIR1 = 1<<17;
	IODIR0 = 1<<25;				   //interupt program for buzzer
	VICIntEnable = 1<<15|1<<17;		 // enabling eint3 and eint1 interrupt
	VICIntSelect = 0<<15|0<<17;		 // selecting as IRQ interrupts 	and 1 for FIQ interrupts
	VICDefVectAddr = (long)(isr);   
	while(1);			 
}