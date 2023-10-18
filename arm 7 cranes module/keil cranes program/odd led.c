#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{	 
		IODIR1 = 0x55555555<<0;	
		while(1)
		{			
		IOSET1 = 0x55555555<<0;       
		delay(1000);
		IOCLR1 = 0x55555555<<0;
		delay(1000);
		}
}
