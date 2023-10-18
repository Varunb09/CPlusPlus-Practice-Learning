#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{	 
	 
	while(1)
	{
		IODIR1 = 0<<25|0xff<<17;	
		if(IOPIN1 & 1<<25)
		{
			int i = 15;
			while(i!=0)						//program to display decrement bcd counter on bit (20 19 18 17)
			{			
				IOSET1 = i<<17;       
				delay(5000);
				IOCLR1 = i<<17;
				delay(5000);
				i--;
			}	 
		}      
		else
		{
			
			int i = 0;
			while(i!=16)						//program to display bcd number on bit (20 19 18 17)
			{	
				if(!IOPIN1 & 1<<25)		
				IOSET1 = i<<17;       
				delay(5000);
				IOCLR1 = i<<17;
				delay(5000);
				i++;
			}
		}			
	}	
}
