#include<lpc214x.h>
#include"lcd link.h"
#include"uart.h"

int flag = 0;
volatile int c = 0;
void eint1_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{  
	
	EXTINT = 1<<1;
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;
	flag = 1;	
	/*d = delete();
	command(0x01);
	command(0x80);
	data1("total:");
	c = c - d;
	display(c);*/
	VICVectAddr = 0;
}
void eint3_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{  
	unsigned int d = 0;
	EXTINT = 1<<3;	
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;	
	d = billing();
	command(0x01);
	command(0x80);
	data1("total:");
	c = c + d;
	display(c);
	flag = 0;
	//c = 0;
	VICVectAddr = 0;
		
}
int main()
{
	unsigned int d = 0;
	command(0x80);	
	IODIR0 = 1<<25;
	lcd();

	PINSEL0 = 1<<29|0<<28;
	VICIntEnable = 1<<15;		 // enabling eint3 interrupt
	VICIntSelect = 0<<15;		 // selecting as IRQ interrupts 	and 1 for FIQ interrupts
	VICVectAddr0 = (long)(eint1_isr);	  //giving address of sub routine to vector address register 
	VICVectCntl0 = 1<<5|15;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 1<<1;					  //edge triggering
	EXTPOLAR = 0<<1;				   //falling edge trigger

	PINSEL1 = 1<<29|0<<28;	
	VICIntEnable = 1<<17;		 // enabling eint3 interupt
	VICIntSelect = 0<<17;		 // selecting as IRQ interupts 	and 1 for FIQ interupts
	VICVectAddr1 = (long)(eint3_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl1 = 1<<5|17;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 1<<3;					  //edge triggering
	EXTPOLAR = 0<<3;				   //falling edge trigger
	while(1)
	{
		if(flag == 1)
		{
			d = delete();
			command(0x01);
			command(0x80);
			data1("total:");
			c = c - d;
			display(c);
			flag = 0;	
		}
	}			 
}
