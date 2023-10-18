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
	int i = 0,j = 0;
	IODIR0 = (0xff<<15|EN|RW|RS|1<<7);			//setting direction of lcd,7 segment 
	IODIR1 = 0xff<<17;							//setting direction of led
	IOCLR1 = 0xff<<17;
	lcd();
	segment();
	digit0(j);
	digit1(j);
	digit2(j);
	digit3(j);
	command(0x80);
	command(0x0c);
	data1("COUNT:");
	while(1)
	{
		while(i!=10)						//program to display decrement bcd counter on bit (20 19 18 17)
		{				
			IOSET1 = i<<17;
			command(0x86);
			display(i);
			delay(2500);
			IOCLR1 = i<<17;
			delay(2500);
			i++;
		}
		j++;
		digit0(j);
		i = 0;

	}
}