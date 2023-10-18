#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{
	IODIR0 =1<<25;				   //program using timer
	T1TCR = 1<<0;
	T1MR0 = 1000000;
	T1PR = 14;
	T1MCR = 0x3<<0;

	while(1)
	{
		if(T1IR & 1<<0)
		{
			IOSET0 = 1<<25;
			delay(1000);
			IOCLR0 = 1<<25;
			T1IR = 1<<0;
		}
	}
}