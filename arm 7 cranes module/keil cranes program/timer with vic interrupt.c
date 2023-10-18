#include<lpc214x.h>
void delay(int c)
{
	int i,j;												   `
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void timer_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
	  //buzzer switching on and off program   
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		T1IR = 1<<0;
}
int main()
{
	IODIR0 =1<<25;				   //program using timer
	T1TCR = 1<<0;
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;

	VICIntEnable = 1<<5;		 // enabling timer interupt
	VICIntSelect = 0<<5;		 // selecting as irq interupts 	and 1 for fiq interupts
	VICVectAddr0 = (long)(timer_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl0 = 1<<5|5;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	while(1);
						   
}

