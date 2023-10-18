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
	T0MR0 = 500000;
	T0MR1 = 1000000;
	T0MR2 = 1500000;
	T0MR3 = 2000000;
	T0PR = 14;				//delay delay time period for timer by formula(t_delay = (1/f)*(PR-1)*(MR_x))
	T0MCR = 0x649<<0;		//given interrupt to both MR1 and MR2 while reset only MR0
	while(1)
	{
		if(T0IR & 1<<0)
		{
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		T0IR = 1<<0;
		}
		
		if(T0IR & 1<<1)				  
		{
		IOSET1 = 1<<17;
		delay(1000);
		IOCLR1 = 1<<17;
		T0IR = 1<<1;
		}		

		if(T0IR & 1<<2)
		{
		IOSET1 = 1<<18;
		delay(1000);
		IOCLR1 = 1<<18;
		T0IR = 1<<2;
		}

		if(T0IR & 1<<3)
		{
		IOSET1 = 1<<19;
		delay(1000);
		IOCLR1 = 1<<19;
		T0IR = 1<<3;
		}
	}
}