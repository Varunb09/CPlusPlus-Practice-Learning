#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i =0;i<c;i++)
	for(j =0;j<1000;j++);

}
int main()
{
	IODIR1 = 1<<17;
	IODIR0 = 1<<25;
	//enabling timer0 and timer 1
	T0TCR = 1<<0;
	T1TCR = 1<<0;
	T0MR0 = 1000000;
	T1MR0 = 1000000;
	T0PR = 14;
	T1PR = 14;				
	T0MCR = 0x0b<<0;
	T1MCR = 0x0b<<0;
	while(1)
	{
		if(T0IR & 1<<0)			  //if statement for timer 0 which ON and OFF led
		{
		IOSET1 = 1<<17;
		delay(1000);
		IOCLR1 = 1<<17;				 
		T0IR = 1<<0;
		}

		if(T1IR & 1<<0)			  //if statement for timer 1 which ON and OFF buzzer
		{
		IOSET0 = 1<<25;
		delay(1000);
		IOCLR0 = 1<<25;
		T1IR = 1<<0;
		}
	}
}