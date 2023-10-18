#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}	/*
int main()
{	 
	SCS=1<<0; //register used to switch between fast and slow gpio
	FIO0DIR = 1<<25;					 
	 
	while(1)
	{	
		FIO0SET = 1<<25;       
		delay(1000);
		FIO0CLR = 1<<25;			
		delay(1000);
	}	
} */

int main()
{	 
	IODIR0 = 1<<25;					 
	 
	while(1)
	{	
		IOSET0 = 1<<25;       
		delay(1000);
		IOCLR0 = 1<<25;			
		delay(1000);
	}	
} 
