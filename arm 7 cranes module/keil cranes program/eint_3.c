#include<lpc214x.h>

void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void eint3_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
	  //buzzer switching on and off program   
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		delay(1000);			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		EXTINT = 1<<3;			 //disabling eint3
}
int main()
{
	PINSEL1 = 1<<29|0<<28;
	IODIR0 = 1<<25;
	VICIntEnable = 1<<17;		 // enabling eint3 interupt
	VICIntSelect = 0<<17;		 // selecting as irq interupts 	and 1 for fiq interupts
	VICVectAddr0 = (long)(eint3_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl0 = 1<<5|17;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 1<<3;					  //edge triggering
	EXTPOLAR = 0<<3;				   //falling edge trigger
	while(1);			 
}
																		
