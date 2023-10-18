#include<lpc214x.h>
void delay(int c)
{
	int i,j;
	for(i = 0;i<c;i++)
	for(j = 0;j<1000;j++);
}
int main()
{	 
						  
	int i = 0;
	while(i!=31)						//program set and clear bit from 0 to 31
	{
		IODIR1 = 1<<i;					   //IODIR1 say direction to port 1
		IOSET1 = 1<<i;       
		delay(1000);
		IOCLR1 = 1<<i;
		delay(1000);
		i++;
	}	
}
