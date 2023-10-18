#include<lpc214x.h>

void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void FIQ_Handler(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
		// switching on and off program   
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		delay(1000);			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		EXTINT = 1<<1;			 //disabling eint3
}
int main()
{
	PINSEL0 = 1<<29|0<<28;
	IODIR0 = 1<<25;
	VICIntEnable = 1<<15;		 // enabling eint3 interupt
	VICIntSelect = 1<<15;		 // selecting 0 as irq interupts 	and 1 for fiq interupts

	EXTMODE = 0<<1;					  //edge triggering
	EXTPOLAR = 0<<1;				   //falling edge trigger
	while(1);			 
}

