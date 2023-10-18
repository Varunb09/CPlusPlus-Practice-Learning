#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
void timer1_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
	  //buzzer switching on and off program   
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		T1IR = 1<<0;
}
void timer0_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
	  //LED switching on and off program   
		IOSET1 = 1<<17;
		delay(1000);
		IOCLR1 = 1<<17;			 //calling delay
		VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
		T0IR = 1<<0;
}
int main()
{
	IODIR0 =1<<25;
	IODIR1 = 1<<17;				 

	T1TCR = 1<<0;					  //timer1
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;

	
	T0TCR = 1<<0;				     //timer0
	T0MR0 = 1000000;
	T0PR = 14;
	T0MCR = 0x3<<0;

	VICIntEnable = 1<<5|1<<4;		 // enabling timer interupt
	VICIntSelect = 0<<5|0<<4;		 // selecting as irq interupts 	and 1 for fiq interupts
	VICVectAddr0 = (long)(timer1_isr);	  //giving address of sub routine to vector address registor
	VICVectAddr1 = (long)(timer0_isr);	  //giving address of sub routine to vector address registor  
	VICVectCntl0 = 1<<5|5;	
	VICVectCntl1 = 1<<5|4;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and (5,4) give id of the address 
	while(1);
						   
}

