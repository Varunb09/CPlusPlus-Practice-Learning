#include<lpc214x.h>

void delay_ms(unsigned int ms)
{
	T0TCR = 0x02;
	T0TCR = 0x01;
	while((T0TC<ms));
	T0TCR = 0x00;
}
void timer_init()
{
	// T0TCR = 1<<0;
	 T0PR = 14999;
	 T0TCR = 1<<1;
}
int main()
{
	 IODIR0 = 1<<25;
	 timer_init();
	 while(1)
	 {
	 	IOSET0 = (1<<25);
		delay_ms(1000);
		IOCLR0 = (1<<25);
		delay_ms(1000);
	 }		
}
