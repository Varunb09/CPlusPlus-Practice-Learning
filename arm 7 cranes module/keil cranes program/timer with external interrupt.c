#include<lpc214x.h>
#include "keypad link lcd.h"
int sec = 0,min = 0,hour = 0;
void display(int c);
void eint3_isr(void)__irq;
void timer_isr(void)__irq;

void eint3_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{	 
    //buzzer switching on and off program   
	IOSET0 = 1<<25;
	delay(1000);
	IOCLR0 = 1<<25;
	VICVectAddr = 0;		 // making address register 0 for reseting address so that cpu resume
	EXTINT = 1<<3;			 //disabling eint3
}
void display(int c)
{
	int d1,d2;
	d1 = c/10;
	d2 = c%10;
	data(d1 + 0x30);
	data(d2 + 0x30);
}
void timer_isr(void)__irq		 // (__irq) is a function qualifier which differentiate between user ans isr function
{
		command(0x80);			 
		sec++;
		display(sec);
		delay(500);
		
		if(sec>59)
		{
				sec = 0;
				min++;
				command(0x85);
				display(min);
				if(min>59)
				{
					min=0;
					sec=0;
					command(0x8a);
					display(hour);
					hour++;
				}
		}
		T1IR = 1<<0;
		VICVectAddr = 0;
}	  

int main()
{
	
	lcd();				   //program using timer
	T1TCR = 1<<0;
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;

	PINSEL1 = 1<<29|0<<28;
	//interrupt for external eint3 buzzer
	VICIntEnable = 1<<17|1<<5;		 // enabling eint3 interupt
	VICIntSelect = 0<<17|0<<5;		 // selecting as irq interupts 	and 1 for fiq interupts
	VICVectAddr0 = (long)(eint3_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl0 = 1<<5|17;				  //'o' for selecting slot 0 of 20 vector regitor and 1 is slot enabling bit at 5th bit of registor and 17 give id of the address 
	EXTMODE = 1<<3;					  //edge triggering
	EXTPOLAR = 0<<3;

	 //interrupt for timer
	VICVectAddr1 = (long)(timer_isr);	  //giving address of sub routine to vector address registor 
	VICVectCntl1 = 1<<5|5;

	while(1);
}