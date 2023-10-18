#include<lpc214x.h>

int main()
{	 
	IODIR0 = 1<<25;
	IODIR1 = 0<<25;
						 
	 
	while(1)
	{	
		if(IOPIN1 & 1<<25)
		{
		IOSET0 = 1<<25; 
		}      
		else
		{
		IOCLR0 = 1<<25;
		}			
	}	
}
