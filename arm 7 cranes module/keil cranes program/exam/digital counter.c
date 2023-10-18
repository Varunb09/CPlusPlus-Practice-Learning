//digital counter till 999 from 0 to 10
#include<lpc214x.h>
#include"lcd interface.h"			//lcd link file
#include"seven segment.h"		 // 7 segment link file
void display(long c)			 //function to display count integer value by scaling the long c value
{
	if(c)
	{
		display(c/10);
		data((c%10)+0x30); 
	}	
}
int main()
{	
	int i = 0,j = 0,k = 0,l = 0,m = 0;
	IODIR0 = (0xff<<15|EN|RW|RS|1<<7);			//setting direction of lcd,7 segment 
	IODIR1 = 0xff<<17;							//setting direction of led
	IOCLR1 = 0xff<<17;
	lcd();
	segment();
	command(0x80);
	command(0x0c);
	data1("COUNT:");
	while(1)
	{
	
		digit0(j);
		digit1(k);
		digit2(l);
		digit3(m);
		while(m != 10)						//loop for digit 4 display
		{
			while(l != 10)						//loop for digit 3 display
			{
				while(k != 10)						//loop for digit 2 display
				{
											//loop for digit 1 display
					while(j != 10)
					{
						while(i!=10)						//program to display decrement bcd counter on bit (20 19 18 17) from 0 to 9
						{				
							IOSET1 = i<<17;
							command(0x86);
							display(i);
							//delay(2500);
							IOCLR1 = i<<17;
							//delay(500);
							i++;
						}
						j++;
						digit3(j);
						i = 0;
					}
					j = 0;
					digit3(j);
					k++;
					digit2(k);
				}
				k = 0;
				digit2(k);
				l++;
				digit1(l);
			}
			l = 0;
			digit1(l);
			m++;
			digit0(m);
		}
	}
}
