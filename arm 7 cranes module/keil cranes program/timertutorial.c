/* DOCUMENTATION
Enable timer     TCR = 1<<0;
delay:MRO = 1000000;
	  PR = 14
	  MCR = 1<<0|1<<1;
while(1)
{
	if(IR & 1<<0)
	{
		set = 1<<25;
		delay
		clear = 1<<25;
		IR = 1<<0;
	}
}*/

#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i =0;i<c;i++)
	for(j =0;j<1000;j++);

}
int main()
{
	IODIR1 = 0xff<<17;
	IODIR0 = 1<<25;
	//enabling timer0
	T0TCR = 1<<0;
	T0MR1 = 1000000;
	T0MR0 = 2000000;
	T0PR = 14;				//delay delay time period for timer by formula(t_delay = (1/f)*(PR-1)*(MR_x))
	T0MCR = 0x0b<<0;		//given interrupt to both MR1 and MR2 while reset only MR0
	while(1)
	{
		if(T0IR &1<<1)				  //if statement for setting up and off led	 after 1M of delay
		{
		IOSET1 = 0xff<<17;
		//delay(1000);
		//IOCLR1 = 0xff<<17;
		IOCLR0 = 1<<25;					  //clearing buzzer in led-if
		T0IR = 1<<1;
		}

		if(T0IR &1<<0)				  //if statement for setting up and off buzzer after 2M	 delay
		{
		IOSET0 = 1<<25;
		//delay(1000);
		IOCLR1 = 0xff<<17;			//clearing led in buzzer-if	 so program run without  delay call
		
		T0IR = 1<<0;
		}
	}
}
	