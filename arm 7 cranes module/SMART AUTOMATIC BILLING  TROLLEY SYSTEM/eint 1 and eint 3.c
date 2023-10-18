#include<lpc214x.h>

void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void eint1_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{		  //led switching on and off program   
		IOSET1 = 1<<17;
		delay(1000);
		IOCLR1 = 1<<17;
		delay(1000);			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		EXTINT = 1<<1;			 //disabling eint3
}
void eint3_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	   //buzzer switching on and off program   
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		delay(1000);			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		EXTINT = 1<<3;			 //disabling eint3
}
int main()
{
	PINSEL0 = 1<<29|0<<28;		   //interrupt program for led
	IODIR1 = 1<<17;
	VICIntEnable = 1<<15;		 // enabling eint3 interrupt
	VICIntSelect = 0<<15;		 // selecting as IRQ interrupts 	and 1 for FIQ interrupts
	VICVectAddr0 = (long)(eint1_isr);	  //giving address of sub routine to vector address register 
	VICVectCntl0 = 1<<5|15;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 0<<1;					  //edge triggering
	EXTPOLAR = 0<<1;				   //falling edge trigger
	
	PINSEL1 = 1<<29|0<<28;			   //interupt program for buzzer
	IODIR0 = 1<<25;
	VICIntEnable = 1<<17;		 // enabling eint3 interupt
	VICIntSelect = 0<<17;		 // selecting as IRQ interupts 	and 1 for FIQ interupts
	VICVectAddr1 = (long)(eint3_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl1 = 1<<5|17;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 0<<3;					  //edge triggering
	EXTPOLAR = 0<<3;				   //falling edge trigger
	while(1);			 
}
