#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{	 
	IODIR0 = 1<<25;
	IODIR1 = 0<<25;
	IODIR1 = 1<<17;
						 
	 
	while(1)
	{	
		if(IOPIN1 & 1<<25)
		{
	    	int i = 17;
	    	while(i != 24)						//program to display decrement bcd counter on bit (20 19 18 17)
		    {
				if(i % 2 == 0)
				{
					IODIR1 = 1<<i;				
					IOSET1 = 1<<i;       
					delay(1000);
					IOCLR1 = 1<<i;
					delay(1000);
					i++;
		        }
				else
					i++;
		   }
		}      
		else
		{
			int i = 17;
	    	while(i != 24)						//program to display decrement bcd counter on bit (20 19 18 17)
		    {
				if(i % 2 != 0)
				{
					IODIR1 = 1<<i;				
					IOSET1 = 1<<i;       
					delay(1000);
					IOCLR1 = 1<<i;
					delay(1000);
					i++;
		        }
				else
					i++;
		   }
		}      		
	}	
}
