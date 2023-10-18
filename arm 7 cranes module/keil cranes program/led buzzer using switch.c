#include<lpc214x.h>

int main()
{	 
	IODIR0 = 1<<25;
	IODIR1 = 0<<25;
	IODIR1 = 1<<17;
						 
	 
	while(1)
	{	
		if(IOPIN1 & 1<<25)
		{
		IOSET0 = 1<<25;
		IOCLR1 = 1<<17;
		 
		}      
		else
		{
		IOSET1 = 1<<17;
		IOCLR0 = 1<<25;
		}			
	}	
}
